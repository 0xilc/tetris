#pragma once
#include <iostream>
#include <unordered_map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class TextureLoader
{
public:
	TextureLoader(const TextureLoader &) = delete;
	TextureLoader &operator=(const TextureLoader &) = delete;

	static TextureLoader &GetInstance()
	{
		static TextureLoader instance;
		return instance;
	}

	GLuint LoadTexture(const std::string &path);
	GLuint GetTexture(const std::string &path) const;
	void DeleteTexture(const std::string &path);

private:
	TextureLoader();

	std::unordered_map<std::string, GLuint> m_Cache;
};
