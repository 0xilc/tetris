#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "rendering/Material.h"
#include "model/Mesh.h"
#include "glm/glm.hpp"
#include <memory>

class GameObject
{
public:
	GameObject();

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;

	void SetPosition(glm::vec2 position);

protected:
	glm::vec2 m_Position;
	glm::vec2 m_Scale;
	glm::mat4 m_ModelMatrix;

	std::shared_ptr<Mesh> m_Mesh;
	std::shared_ptr<Material> m_Material;

	void UpdateModelMatrix();
	glm::mat4 &GetModelMatrix();
};