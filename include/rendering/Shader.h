#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

class Shader
{
public:
	Shader();
	Shader(const std::string &vsPath, const std::string &fsPath);
	~Shader();

	void Load(const std::string &vsPath, const std::string &fsPath);
	void Use();

	void SetUniform1i(const std::string &name, int x);
	void SetUniform1f(const std::string &name, float f);
	void SetUniform3f(const std::string &name, const glm::vec3 &vector);
	void SetUniformMat4fv(const std::string &name, const glm::mat4 &matrix);

	std::string GetVertexPath() const;
	std::string GetFragmentPath() const;

private:
	GLuint ID;
	std::string m_VertexPath;
	std::string m_FragmentPath;
	void checkCompileErrors(GLuint shader, std::string type);
};
