#pragma once
#include "glad/glad.h"
#include "VBO.h"

class VAO
{
public:
	GLuint ID;

	VAO();

	void link_attribute(VBO& VBO, GLuint layout, GLuint n, GLenum type, GLsizeiptr stride, void* offset);

	void bind();

	void unbind();

	void deleet();
};