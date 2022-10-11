// heavily inspired by Victor Gordan's work

#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/rotate_vector.hpp"
#include "glm/gtx/vector_angle.hpp"
#include "glad/glad.h"
#include "include/GLFW/glfw3.h"

#include "Shader.h"
#include "Mouse.h"
#include "main.h"
class Mouse;

class Camera
{
public:
	Camera(unsigned int w, unsigned int h, Vec3 p);

	~Camera();

	void ins(GLFWwindow* window, Mouse& mouse);

	void M(float fov, float near, float far, Shader& shader, const char* variable);

	void clear();

	void boundary();

	void set_bounds(float _x_min, float _x_max, float _y_min, float _y_max, float _z_min, float _z_max);
	void set_bounds(float boundary_array[6]);

	void step();

	//void boundary(float x_bound_low, float x_bound_high, float y_bound_low, float y_bound_high);

	//void boundary(const char* one, const char* two);

public:
	unsigned int width;
	unsigned int height;

	float t = 0.0f;

	Vec3 position;
	Vec3 front;
	Vec3 up;

	float move_speed;
	float time_speed;

	float bg_color[4] = { 0.20, 0.25, 0.30, 0.50 };

	float x_min, x_max;
	float y_min, y_max;
	float z_min, z_max;
};