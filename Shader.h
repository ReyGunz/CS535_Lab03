// heavily inspired by Victor Gordan's work
#pragma once
#include "glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string file_string(const char* filename);

class Shader
{
public:
	GLuint ID;

	float color[4] = { 0.5f, 0.0f, 0.0f, 1.0f };

	Shader(const char* v, const char* f);

	void on();

	void deleet();

	void error_callback(unsigned int shader, const char* type);

	void send_color();

	void update_color(float* _color);
};