#pragma once
#include "glad/glad.h"

#include "VAO.h"
#include "VBO.h"

class Wall
{
public:
	int steps = 8;

	GLfloat verts[9] = {
		-0.5,-0.5,0.0,
		0.5,-0.5,0.0,
		0.5,0.5,0.0
	};

	VAO vao;
	VBO vbo;

	Wall();
	~Wall();

	void init();
	void draw();
};