#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "Camera.h"

#include <iostream>
using Vec3 = glm::vec3;
using Vec2 = glm::vec2;


class Camera;

class Mouse
{
public:
	Mouse();
	~Mouse();

	double lastx, lasty;
	double x, y;
	double pitch, yaw;
	bool first_mouse;

	float sens;

	Vec3 front;
	Vec3 back;
	Vec3 left;
	Vec3 right;

	Vec2 mm_center;
	Vec2 mm_front;
	Vec2 mm_left;
	Vec2 mm_right;

	void update(GLFWwindow* window, Camera* cam);
};