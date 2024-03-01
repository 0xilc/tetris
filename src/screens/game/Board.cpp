#include "app/config.h"
#include "screens/game/Board.h"
#include "screens/game/Tetromino.h"
#include "screens/game/GameState.h"
#include "screens/game/Theme.h"

Board::Board()
{
	// Set the geometry and the material of the mesh.
	m_Mesh = std::make_shared<Quad>();
	m_Material = Theme::GetInstance().GetMaterialGrid();
	m_ModelMatrix = glm::mat4(1.0f);
	m_Position = glm::vec2(0, 0);
	m_Scale = glm::vec2(BOARD_WIDTH + 1, BOARD_HEIGHT + 1);
	UpdateModelMatrix();

	// Initialize the grid
	m_Grid.resize(BOARD_HEIGHT + 3, std::vector<Block>(BOARD_WIDTH));
	for (int i = 0; i < BOARD_HEIGHT + 3; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			m_Grid[i][j].SetPosition(ConvertToWorldPosition({j, i}));
		}
	};
}

void Board::Render()
{
	// Render the board
	m_Material->Use();
	m_Material->GetShader()->SetUniformMat4fv("modelMatrix", GetModelMatrix());
	m_Mesh->Render();

	// Render the grid
	for (std::vector<Block>& row : m_Grid)
	{
		for (Block& block : row)
		{
			block.Render();
		}
	}
}

void Board::Update(float deltaTime)
{
	CheckGameEnded();
	ClearLines();
}

void Board::PlaceTetromino(Tetromino& tetromino)
{
	std::shared_ptr<Material> mat = tetromino.GetMaterial();
	std::vector<glm::vec2> blockPositions = tetromino.GetBlockGridPositions();
	for (glm::vec2 position : blockPositions)
	{
		m_Grid[(int)position.y][(int)position.x].SetMaterial(mat);
	}
}

bool Board::CheckCollision(int x, int y)
{
	if (x < 0 || x >= BOARD_WIDTH || y < 0)
	{
		return true;
	}
	return (!m_Grid[y][x].IsEmpty());
}

glm::vec2 Board::ConvertToGridPosition(glm::vec2 position)
{
	return glm::vec2(position.x + BOARD_WIDTH / 2 - 0.5, position.y + BOARD_HEIGHT / 2 - 0.5);
}

glm::vec2 Board::ConvertToWorldPosition(glm::vec2 position)
{
	return glm::vec2(position.x - BOARD_WIDTH / 2 + 0.5, position.y - BOARD_HEIGHT / 2 + 0.5);
}

void Board::CheckGameEnded()
{
	for (auto& block : m_Grid[BOARD_HEIGHT])
	{
		if (!block.IsEmpty())
		{
			GameState::GetInstance().SetGameContinues(false);
		}
	}
}

void Board::ClearLines()
{
	int clearedLineCount = 0;
	for(auto& row : m_Grid)
	{
		bool isFull = true;
		for (auto& block : row)
		{
			if (block.IsEmpty())
			{
				isFull = false;
				break;
			}
		}
		if (isFull)
		{
			clearedLineCount++;
			for (auto& block : row)
			{
				block.Clear();
			}
			ShiftLinesDown(&row - &m_Grid[0]);

		}
	}

	GameState::GetInstance().IncrementScore(clearedLineCount * 1000);
}

void Board::ShiftLinesDown(int row)
{
	for (int i = row; i < BOARD_HEIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIDTH; j++)
		{
			m_Grid[i][j].Swap(m_Grid[i + 1][j]);
		}
	}
}
