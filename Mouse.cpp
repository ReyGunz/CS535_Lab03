#include "Mouse.h"

Mouse::Mouse()
{
    x = 0.0f;
    y = 0.0f;
    lastx = 0.0f; lasty = 0.0f;
    pitch = 0.0f; yaw = 0.0f;
    first_mouse = true;
    sens = 0.5f;

    front = Vec3(0);
    back = Vec3(0);
    left = Vec3(0);
    right = Vec3(0);
}

Mouse::~Mouse()
{
}

void Mouse::update(GLFWwindow* window, Camera* cam)
{
    Vec3 c_up(cam->up);
	glfwGetCursorPos(window, &x, &y);

	if (first_mouse)
    {
        lastx = x;
        lasty = y;
        first_mouse = false;
    }

   float xoff = x - lastx;
   float yoff = lasty - y;
   lastx = x;
   lasty = y;

   //float sens = 1.0f;
   xoff *= sens;
   yoff *= sens;

   yaw += xoff;
   pitch += yoff;

   if (pitch > M_PI_2) {
       pitch = M_PI_2 - 0.0001f;
   }
   else if (pitch < -M_PI_2) {
       pitch = -M_PI_2 + 0.0001f;
   }

   front = glm::normalize(Vec3(
                                       cos(glm::radians(yaw)),
                                       0,
                                       sin(glm::radians(yaw)))
                                     );

   back = -front;
   right = glm::normalize(glm::cross(front, c_up));
   left = -right;
}