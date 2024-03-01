#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <unordered_map>
#include <string>
#include <memory>
#include "Shader.h"

class ShaderManager
{
public:

	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;

	static ShaderManager& GetInstance() {
		static ShaderManager instance;
		return instance;
	}

	std::shared_ptr<Shader> LoadShader(const std::shared_ptr<Shader>& shader);
	std::shared_ptr<Shader> LoadShader(const std::string& vsPath, const std::string& fsPath);
	std::shared_ptr<Shader> GetShader(const std::string& vsPath, const std::string& fsPath) const;

private:
	ShaderManager();

	std::unordered_map<std::string, std::shared_ptr<Shader>> m_Cache;
};