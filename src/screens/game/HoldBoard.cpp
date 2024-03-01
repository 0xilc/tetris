#include "app/config.h"
#include "screens/game/HoldBoard.h"

HoldBoard::HoldBoard()
{	
	m_Mesh = std::make_shared<Quad>();
	m_Material = std::make_shared<Material>("assets/shaders/board.vert", "assets/shaders/board.frag");
	m_Material->SetDiffuseTexture("assets/textures/board.jpg");
	m_ModelMatrix = glm::mat4(1.0f);
	m_Scale = glm::vec2(5, 5);
	m_Position = glm::vec2((-BOARD_WIDTH / 2) - 3.5, (BOARD_HEIGHT / 2) - 2);
	UpdateModelMatrix();
}

void HoldBoard::Render()
{
	m_Material->Use();
	m_Material->GetShader()->SetUniformMat4fv("modelMatrix", GetModelMatrix());
	m_Mesh->Render();

	if (m_HoldTetromino != nullptr)
	{
		m_HoldTetromino->RenderInFrame(m_Position);
	}
}

void HoldBoard::Update(float deltaTime)
{
	m_HoldTetromino->Update(deltaTime);
}

bool HoldBoard::IsEmpty() const
{
	return (m_HoldTetromino == nullptr);
}

void HoldBoard::SetTetromino(std::shared_ptr<Tetromino> tetromino)
{
	m_HoldTetromino = tetromino;
	m_HoldTetromino->Refactor();
	m_HoldTetromino->SetPosition(m_Position);
}

std::shared_ptr<Tetromino> HoldBoard::SwapTetromino(std::shared_ptr<Tetromino> tetromino)
{
	std::shared_ptr<Tetromino> temp = m_HoldTetromino;
	temp->Refactor();
	SetTetromino(tetromino);
	return temp;
}