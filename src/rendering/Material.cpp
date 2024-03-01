#include "rendering/Material.h"
#include "rendering/TextureLoader.h"

Material::Material()
{
}

Material::Material(std::shared_ptr<Shader> shader)
{
	m_Shader = shader;
	m_DiffuseTexture = 0;
	m_SpecularTexture = 0;
	m_NormalTexture = 0;

	m_DiffuseCoefficient = 1;
	m_SpecularCoefficient = 1;
	m_NormalCoefficient = 1;
}

Material::Material(const std::string& vsPath, const std::string& fsPath)
{
	m_Shader = std::make_shared<Shader>(vsPath, fsPath);

	m_DiffuseTexture = 0;
	m_SpecularTexture = 0;
	m_NormalTexture = 0;

	m_DiffuseCoefficient = 1;
	m_SpecularCoefficient = 1;
	m_NormalCoefficient = 1;
}
Material::~Material() {}

void Material::SetShader(std::shared_ptr<Shader> shader)
{
	m_Shader = shader;
}

void Material::SetDiffuseTexture(GLuint textureID)
{
	m_DiffuseTexture = textureID;
}
void Material::SetDiffuseTexture(const std::string& path)
{
	m_DiffuseTexture = TextureLoader::GetInstance().LoadTexture(path);
}
void Material::SetSpecularTexture(GLuint textureID)
{
	m_SpecularTexture = textureID;
}
void Material::SetSpecularTexture(const std::string& path)
{
	m_SpecularTexture = TextureLoader::GetInstance().LoadTexture(path);
}
void Material::SetNormalTexture(GLuint textureID)
{
	m_NormalTexture = textureID;
}
void Material::SetNormalTexture(const std::string& path)
{
	m_NormalTexture = TextureLoader::GetInstance().LoadTexture(path);
}

std::shared_ptr<Shader> Material::GetShader()
{
	return m_Shader;
}

void Material::Use()
{
	m_Shader->Use();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_DiffuseTexture);
	m_Shader->SetUniform1i("textureDiffuse", 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, m_SpecularTexture);
	m_Shader->SetUniform1i("textureSpecular", 1);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, m_NormalTexture);
	m_Shader->SetUniform1i("textureNormal", 2);

}
