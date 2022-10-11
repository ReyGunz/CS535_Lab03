#include "Camera.h"

Camera::Camera(unsigned int w, unsigned int h, Vec3 p)
{
	width = w;
	height = h;
	position = p;

	front = Vec3(0, 0, -1);
	up = Vec3(0, 1, 0);

	move_speed = 0.25f;
	time_speed = 0.01f;

	//bg_color = {0.20, 0.25, 0.30, 0.50};
}

Camera::~Camera()
{

}

void Camera::ins(GLFWwindow* window, Mouse& mouse)
{
	mouse.update(window, this);
	front = mouse.front;

	if (glfwGetKey(window, GLFW_KEY_W))
	{
		position += move_speed * mouse.front;
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		position += move_speed * mouse.back;
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		position += move_speed * mouse.right;
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		position += move_speed * mouse.left;
	}
	if(glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		return;
	}
}

void Camera::M(float fov, float near, float far, Shader& shader, const char* variable)
{
	glm::mat4 view = glm::mat4(1.0);
	glm::mat4 proj = glm::mat4(1.0);

	view = glm::lookAt(position, position + front, up);
	proj = glm::perspective(glm::radians(fov), (float)width / height, near, far);

	glUniformMatrix4fv(glGetUniformLocation(shader.ID, variable), 1, GL_FALSE, glm::value_ptr(proj * view));
}

void Camera::clear()
{
	glClearColor(bg_color[0], bg_color[1], bg_color[2], bg_color[3]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Camera::boundary()
{
	if (position.x < x_min) position.x = x_min;
	if (position.x > x_max) position.x = x_max;
	if (position.y < y_min) position.y = y_min;
	if (position.y > y_max) position.y = y_max;
	if (position.z < z_min) position.z = z_min;
	if (position.z > z_max) position.z = z_max;
}

void Camera::set_bounds(float _x_min, float _x_max, float _y_min, float _y_max, float _z_min, float _z_max)
{
	x_min = _x_min;
	x_max = _x_max;
	y_min = _y_min;
	y_max = _y_max;
	z_min = _z_min;
	z_max = _z_max;
}

void Camera::set_bounds(float boundary_array[6])
{
	x_min = boundary_array[0];
	x_max = boundary_array[1];
	y_min = boundary_array[2];
	y_max = boundary_array[3];
	z_min = boundary_array[4];
	z_max = boundary_array[5];
}

void Camera::step()
{
	t += time_speed;
}

//void Camera::boundary(float x_bound_low, float x_bound_high, float z_bound_low, float z_bound_high)
//{
//	if (position.x < x_bound_low) position.x = x_bound_low;
//	if (position.x > x_bound_high) position.x = x_bound_high;
//	if (position.z < z_bound_low) position.z = z_bound_low;
//	if (position.z > z_bound_high) position.z = z_bound_high;
//}
//
//void Camera::boundary(const char* one, const char* two)
//{
//	if (one == "x" || two == "x")
//	{
//		if (one == "y" || two == "y")
//		{
//
//			if (position.x < x_min) position.x = x_min;
//			if (position.x > x_max) position.x = x_max;
//			if (position.y < y_min) position.z = z_bound_low;
//			if (position.y > z_bound_high) position.z = z_bound_high;
//		}
//	}
//}
