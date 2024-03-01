#include "rendering/ShaderManager.h"

ShaderManager::ShaderManager()
{
}

std::shared_ptr<Shader> ShaderManager::LoadShader(const std::string& vsPath, const std::string& fsPath)
{
	std::string key = vsPath + fsPath;
	auto it = m_Cache.find(key);
	if (it != m_Cache.end())
	{
		return it->second;
	}

	std::shared_ptr<Shader> shader = std::make_shared<Shader> (vsPath, fsPath);
	m_Cache[key] = shader;
	return shader;
}

std::shared_ptr<Shader> ShaderManager::LoadShader(const std::shared_ptr<Shader>& shader)
{
	std::string key = shader->GetVertexPath() + shader->GetFragmentPath();
	auto it = m_Cache.find(key);
	if (it != m_Cache.end())
	{
		return it->second;
	}

	m_Cache[key] = shader;
	return shader;
}

std::shared_ptr<Shader> ShaderManager::GetShader(const std::string& vsPath, const std::string& fsPath) const
{
	std::string key = vsPath + fsPath;
	auto it = m_Cache.find(key);
	if (it != m_Cache.end())
	{
		return it->second;
	}
	return nullptr;
}


