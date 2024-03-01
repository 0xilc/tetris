#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Mesh
{
public:
	virtual void Render() = 0;
};