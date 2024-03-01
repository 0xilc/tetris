#include "app/Input.h"
#include "app/config.h"
#include "screens/game/GameState.h"
#include "screens/game/Tetromino.h"
#include "screens/game/Theme.h"
#include "screens/game/Board.h"

Tetromino::Tetromino(std::shared_ptr<Board> board)
{
	m_Block = std::make_unique<Block>();
	m_GhostMaterial = Theme::GetInstance().GetMaterialGhost();
	m_GhostMaterial->SetDiffuseTexture("assets/textures/block/blue.png");
	m_Position = { 0.5, (BOARD_HEIGHT / 2) + 0.5 };
	m_MoveSpeed = MOVE_SPEED;
	m_MoveDelay = 1.0f / m_MoveSpeed * 0.1f;
	m_Board = board;
	m_IsPlaced = false;
}

void Tetromino::Render()
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_RelativePositions)
	{
		glm::vec2 worldPos = m_Position + relPos;
		m_Block->SetPosition(worldPos);
		m_Block->Render();
	}
}

void Tetromino::RenderGhost() const
{
	m_Block->SetMaterial(m_GhostMaterial);
	for (auto& relPos : m_RelativePositions)
	{
		glm::vec2 worldPos = m_GhostTetrominoPosition + relPos;
		m_Block->SetPosition(worldPos);
		m_Block->Render();
	}
}

void Tetromino::Update(float deltaTime)
{
	HandleInput();
	m_FallTimer += deltaTime * (1 + GameState::GetInstance().GetGameSpeed());
	m_TimeSinceLastMove += deltaTime;
	
	if (m_FallTimer > 1)
	{
		m_FallTimer = 0;
		Move({ 0, -1 });
	}
	if (IsOnSurface())
	{
		if (m_StayOnSurfaceTimer < 0)
		{
			PlaceToBoard();
		}
		else
		{
			m_StayOnSurfaceTimer -= deltaTime;
		}
	}

	m_GhostTetrominoPosition = FindDropPosition();
}

void Tetromino::Move(glm::vec2 direction)
{
	glm::vec2 newPos = m_Position + direction;
	if (CheckCollision(newPos)) return;
	m_Position = newPos;

}

void Tetromino::Drop()
{
	m_Position = m_GhostTetrominoPosition;
	PlaceToBoard();
}

void Tetromino::Rotate(RotationType type)
{
	std::vector<glm::vec2> tempRelativePos = m_RelativePositions;

	switch (type)
	{
	case ROTATE_CCLOCKWISE:
		for (auto& relPos : m_RelativePositions)
		{
			glm::vec2 newPos = { -relPos.y, relPos.x };
			relPos = newPos;
		}
		break;

	case ROTATE_CLOCKWISE:
		for (auto& relPos : m_RelativePositions)
		{
			glm::vec2 newPos = { relPos.y, -relPos.x };
			relPos = newPos;
		}
		break;
	
	case ROTATE_180:
		for (auto& relPos : m_RelativePositions)
		{
			relPos.x = -relPos.x;
			relPos.y = -relPos.y;
		}
		break;

	}
	
	if (CheckCollision(m_Position)) 
	{
		m_RelativePositions = tempRelativePos; 
	}
}

void Tetromino::Refactor()
{
	m_Position = { 0.5, (BOARD_HEIGHT / 2) + 0.5 };
	m_RelativePositions = m_DefaultRelativePositions;
	m_IsPlaced = false;
	m_FallTimer = 0;
	m_GhostTetrominoPosition = FindDropPosition();
}

bool Tetromino::IsPlaced() const
{
	return m_IsPlaced;
}

bool Tetromino::CheckCollision(glm::vec2 position)
{
	for (auto& relPos : m_RelativePositions)
	{
		glm::vec2 gridPos = Board::ConvertToGridPosition(position + relPos);
		if (m_Board->CheckCollision(std::floor(gridPos.x), std::floor(gridPos.y))) return true;
	}
	return false;
}

bool Tetromino::IsOnSurface() const
{
	return (m_Position == m_GhostTetrominoPosition);
}

void Tetromino::PlaceToBoard()
{
	m_Board->PlaceTetromino(*this);
	m_IsPlaced = true;
}

void Tetromino::HandleInput()
{
	if (Input::IsKeyPressed(MOVE_LEFT_KEY)) {
		if (m_TimeSinceLastMove < m_MoveDelay) return;
		Move({-1, 0});
		m_TimeSinceLastMove = 0;
	}

	else if (Input::IsKeyPressed(MOVE_RIGHT_KEY)) {
		if (m_TimeSinceLastMove < m_MoveDelay) return;
		Move({1, 0});
		m_TimeSinceLastMove = 0;
	}

	else if (Input::IsKeyPressed(SOFT_DROP_KEY)) {
		if (m_TimeSinceLastMove < m_MoveDelay) return;
		Move({0, -1});
		m_TimeSinceLastMove = 0;
	}

	if (Input::IsKeyPressed(HARD_DROP_KEY))
	{
		if (!m_CanDrop) return;
		Drop();
		m_CanDrop = false;
	}

	if (Input::IsKeyPressed(ROTATE_CLOCKWISE_KEY))
	{
		if (!m_CanRotate) return;
		Rotate(ROTATE_CLOCKWISE);
		m_CanRotate = false;
	}

	if (Input::IsKeyPressed(ROTATE_CCLOCKWISE_KEY))
	{
		if (!m_CanRotate) return;
		Rotate(ROTATE_CCLOCKWISE);
		m_CanRotate = false;
	}

	if (Input::IsKeyPressed(ROTATE_180_KEY))
	{
		if (!m_CanRotate) return;
		Rotate(ROTATE_180);
		m_CanRotate = false;
	}

	if (   !Input::IsKeyPressed(ROTATE_CLOCKWISE_KEY) 
		&& !Input::IsKeyPressed(ROTATE_CCLOCKWISE_KEY) 
		&& !Input::IsKeyPressed(ROTATE_180_KEY))
	{
		m_CanRotate = true;
	}

	if (!Input::IsKeyPressed(HARD_DROP_KEY))
	{
		m_CanDrop = true;
	}
}

std::vector<glm::vec2> Tetromino::GetBlockGridPositions() const
{
	std::vector<glm::vec2> positions;
	for (auto& relPos : m_RelativePositions)
	{
		glm::vec2 worldPos = m_Position + relPos;
		glm::vec2 gridPos = Board::ConvertToGridPosition(worldPos);
		positions.push_back(gridPos);
	}
	return positions;
}

std::shared_ptr<Material> Tetromino::GetMaterial() const
{
	return m_Material;
}

void Tetromino::PrintPos()
{
	for (auto& relPos : m_RelativePositions)
	{
		glm::vec2 worldPos = m_Position + relPos;
		glm::vec2 gridPos = Board::ConvertToGridPosition(worldPos);
		std::cout << "grid x: " << gridPos.x << " grid y: " << gridPos.y << std::endl;
	}
}

glm::vec2 Tetromino::FindDropPosition()
{
	glm::vec2 pos = m_Position;
	while (!CheckCollision(pos))
	{
		pos.y -= 1;
	}
	return (pos + glm::vec2(0, 1));
}

