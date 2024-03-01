#include "screens/game/Shapes.h"
#include "screens/game/Theme.h"

LShape::LShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{-1, 0},
		{1, 1},
		{1, 0}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialLShape();	
	m_Block->SetMaterial(m_Material);
}

void LShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	std::vector<glm::vec2> blockPositions = {
		{0, 0},
		{-1, 0},
		{1, 1},
		{1, 0}
	};
	for (auto& relPos : blockPositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(0, -0.5));
		m_Block->Render();
	}
}

JShape::JShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{-1, 0},
		{-1, 1},
		{1, 0}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialJShape();
	m_Material->SetDiffuseTexture("assets/textures/block/blue.png");
	m_Block->SetMaterial(m_Material);
}

void JShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_DefaultRelativePositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(0, -0.5));
		m_Block->Render();
	}
}

OShape::OShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{0, 1},
		{1, 0},
		{1, 1}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialOShape();
	m_Block->SetMaterial(m_Material);
}

void OShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_DefaultRelativePositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(-0.5, -0.5));
		m_Block->Render();
	}
}

SShape::SShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{0, 1},
		{1, 1},
		{-1, 0}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialSShape();
	m_Block->SetMaterial(m_Material);
}

void SShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_DefaultRelativePositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(0, -0.5));
		m_Block->Render();
	}
}

TShape::TShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{-1, 0},
		{1, 0},
		{0, 1}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialTShape();
	m_Block->SetMaterial(m_Material);
}

void TShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_DefaultRelativePositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(0, -0.5));
		m_Block->Render();
	}
}

ZShape::ZShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{1, 0},
		{0, 1},
		{-1, 1}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialZShape();
	m_Block->SetMaterial(m_Material);
}

void ZShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_DefaultRelativePositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(0, -0.5));
		m_Block->Render();
	}
}

IShape::IShape(std::shared_ptr<Board> board) : Tetromino(board)
{
	m_DefaultRelativePositions = {
		{0, 0},
		{-1, 0},
		{-2, 0},
		{1, 0}
	};
	m_RelativePositions = m_DefaultRelativePositions;
	m_Material = Theme::GetInstance().GetMaterialIShape();
	m_Block->SetMaterial(m_Material);
}

void IShape::RenderInFrame(glm::vec2 position) const
{
	m_Block->SetMaterial(m_Material);
	for (auto& relPos : m_DefaultRelativePositions)
	{
		m_Block->SetPosition(position + relPos + glm::vec2(0.5, 0));
		m_Block->Render();
	}
}
