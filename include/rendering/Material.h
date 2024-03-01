#pragma once
#include "rendering/Shader.h"
#include "Camera.h"
class Material
{
public:
	Material();
	Material(std::shared_ptr<Shader> shader);
	Material(const std::string &vsPath, const std::string &fsPath);
	~Material();

	void SetShader(std::shared_ptr<Shader> shader);

	void SetDiffuseTexture(GLuint textureID);
	void SetDiffuseTexture(const std::string &path);

	void SetSpecularTexture(GLuint textureID);
	void SetSpecularTexture(const std::string &path);

	void SetNormalTexture(GLuint textureID);
	void SetNormalTexture(const std::string &path);

	std::shared_ptr<Shader> GetShader();

	void Use();

private:
	std::shared_ptr<Shader> m_Shader;

	GLuint m_DiffuseTexture;
	GLuint m_SpecularTexture;
	GLuint m_NormalTexture;

	// material properties
	float m_DiffuseCoefficient;
	float m_SpecularCoefficient;
	float m_NormalCoefficient;
};
