#pragma once

#include "VAO.h"
#include "VBO.h"
#include "glm/glm.hpp"
#include "main.h"

#include <iostream>

using Color3 = glm::vec3;
using Vec3 = glm::vec3;
using Mat3 = glm::mat3;
using Mat4 = glm::mat4;

class Dummy
{
private:
	int stacks = 25, slices = 25;
	int points, normals;
	GLfloat r = 1.f;

	Color3 color = Color3(1,0,0);
	std::vector<GLfloat> verts;
	std::vector<GLfloat> colors;
	//std::vector<GLfloat> norms;

	VAO vao;
	VBO vbo = VBO(2);

	Mat4 model;
	Mat3 model_view_n;

public:
	Dummy();
	~Dummy();

	void generate(int _stacks, int _slices, GLfloat _r);
	void init();
	void draw();
	void set_model(Mat4 tmp);
	void set_model_view_n(Mat3 tmp);
};