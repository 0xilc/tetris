#pragma once
#include "model/Mesh.h"

class Quad : public Mesh
{
public:
	Quad();

	void Render() override;

private:
	GLuint m_VAO;
};