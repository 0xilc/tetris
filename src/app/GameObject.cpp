#include "app/GameObject.h"

GameObject::GameObject()
{
	m_Position = glm::vec2(0,0);
	m_Scale = glm::vec2(1, 1);
	UpdateModelMatrix();
}

void GameObject::SetPosition(glm::vec2 position)
{
	m_Position = position;
	UpdateModelMatrix();
}

glm::mat4& GameObject::GetModelMatrix()
{
	return m_ModelMatrix;
}

void GameObject::UpdateModelMatrix()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(m_Position, 0.0f));
	model = glm::scale(model, glm::vec3(m_Scale, 1.0f));
	m_ModelMatrix = model;
}
