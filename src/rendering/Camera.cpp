#include "rendering/Camera.h"

Camera::Camera()
{
	m_NearPlane.left = 10;
	m_NearPlane.right = -10;
	m_NearPlane.top = 10;
	m_NearPlane.bottom = -10;
	m_Zoom = 1;
	CalculateProjectionMatrix();
	CalculateViewMatrix();
}

Camera::Camera(int windowWidth, int windowHeight)
{
	double aspectRatio = windowWidth / windowHeight;

	m_NearPlane.left = -(15 * aspectRatio);
	m_NearPlane.right = (15 * aspectRatio);
	m_NearPlane.top = 15;
	m_NearPlane.bottom = -15;
	CalculateProjectionMatrix();
	CalculateViewMatrix();
}


void Camera::Resize(int windowWidth, int windowHeight)
{
	double aspectRatio = (double)windowWidth / windowHeight;
	
	m_NearPlane.left = -(15 * aspectRatio);
	m_NearPlane.right = (15 * aspectRatio);
	m_NearPlane.top = 15;
	m_NearPlane.bottom = -15;
	CalculateProjectionMatrix();
	CalculateViewMatrix();
}

void Camera::SetZoom(float zoom)
{
	m_Zoom = zoom;
}

void Camera::SetUniforms(UBOManager& uboManager)
{
	glm::mat4 viewMatrix = this->GetViewMatrix();
	glm::mat4 projectionMatrix = this->GetProjectionMatrix();

	uboManager.UpdateUBO("CameraData", 0, sizeof(glm::mat4), glm::value_ptr(viewMatrix));
	uboManager.UpdateUBO("CameraData", sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(projectionMatrix));
}

glm::mat4 Camera::GetViewMatrix() const
{
	return m_ViewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix() const 
{
	return m_ProjectionMatrix;
}

void Camera::CalculateViewMatrix()
{
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	m_ViewMatrix = glm::inverse(transform);
	m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
}

void Camera::CalculateProjectionMatrix()
{
	m_ProjectionMatrix = glm::ortho(
		m_NearPlane.left * m_Zoom,
		m_NearPlane.right * m_Zoom,
		m_NearPlane.bottom * m_Zoom,
		m_NearPlane.top * m_Zoom, -1.0f, 1.0f);

	m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
}
