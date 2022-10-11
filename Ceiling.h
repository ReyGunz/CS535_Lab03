#pragma once
#include "glad/glad.h"

#include "VAO.h"
#include "VBO.h"

class Ceiling
{
public:
	int steps = 8;

	GLfloat verts[18] = {
		-10.0,1.0,-10.0,
		10.0,1.0,-10.0,
		10.0,1.0,10.0,
		-10.0,1.0,-10.0,
		10.0,1.0,10.0,
		-10.0,1.0,10.0
	};

	VAO vao;
	VBO vbo;

	Ceiling();
	Ceiling(int w, int h);
	~Ceiling();

	void init();
	void init(int w, int h);
	void draw();
};