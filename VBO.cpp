#include "VBO.h"

VBO::VBO()
{
	ID = new GLuint;
	glGenBuffers(1, ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID[0]);
}

VBO::VBO(const int size)
{
	ID = new GLuint[size];
	glGenBuffers(size, ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID[0]);
}

void VBO::update(GLfloat* vertices, GLsizeiptr size)
{
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::update(std::vector<GLfloat> vertices, GLsizeiptr size)
{
	glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], GL_STATIC_DRAW);
}

VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID[0]);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID[0]);
}

void VBO::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::deleet()
{
	glDeleteBuffers(1, ID);
}