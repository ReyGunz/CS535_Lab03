#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <vector>

class VBO
{
public:
	GLuint* ID;
	// std::vector<GLuint> ID;

	VBO();
	VBO(const int size);
	VBO(GLfloat* vertices, GLsizeiptr size);

	void update(GLfloat* vertices, GLsizeiptr size);
	void update(std::vector<GLfloat> vertices, GLsizeiptr size);

	void bind();

	void unbind();

	void deleet();
};
