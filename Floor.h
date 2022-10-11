#pragma once
#include "glad/glad.h"

#include "VAO.h"
#include "VBO.h"
#include "glm/glm.hpp"
#include "main.h"

#include <iostream>

using Color3 = glm::vec3;
using Vec3 = glm::vec3;

class Floor
{
public:
	int steps = 8;
	int points;

	Vec3 norm = Vec3(0,1,0);

	int t_steps = 11;
	const int CAPACITY = t_steps * 6;
	Color3 color;

	std::vector<GLfloat> verts2;

	//GLfloat verts[36] = {
	//	-10.0,-1.0,-10.0,	1,0,0,
	//	10.0,-1.0,-10.0,	1,0,0,
	//	10.0,-1.0,10.0,		1,0,0,
	//	-10.0,-1.0,-10.0,	1,0,0,
	//	10.0,-1.0,10.0,		1,0,0,
	//	-10.0,-1.0,10.0,	1,0,0
	//};

	//Color color = glm::vec4(1,0,0,1);
	//std::vector<Color> colors;

	//GLfloat colors[24] = {
	//	1,0,0,1,
	//	1,0,0,1,
	//	1,0,0,1,
	//	1,0,0,1,
	//	1,0,0,1,
	//	1,0,0,1
	//};

	VAO vao;
	VBO vbo;

	Floor();
	Floor(int w, int h);
	~Floor();

	void init();
	void init(int w, int h);
	void draw();
};