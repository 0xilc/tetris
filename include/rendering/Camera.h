#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "UBOManager.h"

struct NearPlane
{
	float left, right, top, bottom;
};

class Camera
{
public:
	Camera();
	Camera(int windowWidth, int windowHeight);

	void Resize(int windowWidth, int windowHeight);
	void SetZoom(float zoom);

	void SetUniforms(UBOManager &uboManager);

	glm::mat4 GetViewMatrix() const;
	glm::mat4 GetProjectionMatrix() const;

private:
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewProjectionMatrix;

	void CalculateViewMatrix();
	void CalculateProjectionMatrix();

	NearPlane m_NearPlane;
	float m_Zoom;
};