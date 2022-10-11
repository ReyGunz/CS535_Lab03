#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "main.h"

#include <vector>

class Shape
{
protected:
	Mat4 model;
	Mat3 model_view_n;
	GLubyte color[3];

	std::vector<GLfloat>* a;
	std::vector<GLfloat> vertex;
	std::vector<GLfloat> normal;

	VAO vao;
	VBO* vbo;

	GLuint buffer, points, normals;

public:
	virtual void set_model(Mat4 tmp);
	virtual void set_model_view_n(Mat3 tmp);
	virtual void set_color(GLubyte r, GLubyte b, GLubyte g);
	virtual void draw();
	//virtual void move(float x, float y, float z);
};

