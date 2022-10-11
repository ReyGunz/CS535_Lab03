#pragma once
//#include "Shape.h"
//#include "main.h"
//
//class Dummy : public Shape
//{
//public:
//	Dummy();
//	Dummy(int stacks, int slices, GLfloat r);
//
//	void init_arrays();
//	void generate(int stacks, int slices, GLfloat r);
//	void draw();
//
//private:
//	GLuint vaID, vboHandles[2];
//
//	int points, normals;
//	int stacks;
//	int slices;
//	GLfloat r;
//
//	std::vector<GLfloat> vertex;
//	std::vector<GLfloat> normal;
//};

#include "VAO.h"
#include "VBO.h"
#include "glm/glm.hpp"
#include "main.h"

#include <iostream>

using Color3 = glm::vec3;
using Vec3 = glm::vec3;

class Ammo
{
private:
	int stacks = 25, slices = 25;
	int points, normals;
	GLfloat r = 1.f;

	Color3 color = Color3(1, 1, 0);
	std::vector<GLfloat> verts;
	std::vector<GLfloat> colors;
	//std::vector<GLfloat> norms;

	VAO vao;
	VBO vbo = VBO(2);

public:
	Ammo();
	~Ammo();

	void generate(int _stacks, int _slices, GLfloat _r);
	void init();
	void draw();
};