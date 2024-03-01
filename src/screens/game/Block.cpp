#include "screens/game/Block.h"

Block::Block()
{
    m_Mesh = std::make_shared<Quad>();
    m_Material = std::make_shared<Material>("assets/shaders/block/empty.vert", "assets/shaders/block/empty.frag");
    m_ModelMatrix = glm::mat4(1.0f);
    m_Position = glm::vec2(0, 0);
    m_Scale = glm::vec2(1, 1);
    UpdateModelMatrix();
    SetEmpty(true);
}

Block::Block(std::shared_ptr<Material> material)
{
    m_Mesh = std::make_shared<Quad>();
    m_Material = material;
    m_ModelMatrix = glm::mat4(1.0f);
    m_Position = glm::vec2(0, 0);
    m_Scale = glm::vec2(1, 1);
    UpdateModelMatrix();
    SetEmpty(false);
}

void Block::Render()
{
    m_Material->Use();
    m_Material->GetShader()->SetUniformMat4fv("modelMatrix", GetModelMatrix());
    m_Mesh->Render();
}

void Block::Update(float deltaTime)
{
}

void Block::Swap(Block& other)
{
	std::swap(m_Material, other.m_Material);
	std::swap(m_IsEmpty, other.m_IsEmpty);
}

void Block::Clear()
{
	m_Material = std::make_shared<Material>("assets/shaders/block/empty.vert", "assets/shaders/block/empty.frag");
    SetEmpty(true);
}

bool Block::IsEmpty() const
{
    return m_IsEmpty;
}

void Block::SetEmpty(bool isEmpty)
{
    m_IsEmpty = isEmpty;
}

void Block::SetMaterial(std::shared_ptr<Material> material)
{
    m_Material = material;
    SetEmpty(false);
}
