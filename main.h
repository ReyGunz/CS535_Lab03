#ifndef MAIN_H
#define MAIN_H

#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"

#include "include/imgui/imgui.h"
#include "include/imgui/backends/imgui_impl_glfw.h"
#include "include/imgui/backends/imgui_impl_opengl3.h"

#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <vector>

#include "Shader.h"
#include "Camera.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Wall.h"
#include "Floor.h"
#include "Mouse.h"
#include "Ceiling.h"
#include "Dummy.h"
#include "Ammo.h"
using Color3 = glm::vec3;
using Color4 = glm::vec4;
using Vec2 = glm::vec2;
using Vec3 = glm::vec3;
using Vec4 = glm::vec4;
using Mat4 = glm::mat4;
using Mat3 = glm::mat3;

const int width = 1920, height = 1080;
const int floor_w = 50, floor_h = 50;
const int ceiling_w = 25, ceiling_h = 25;
const float fov = 60.0f;
const float near = 0.01f, far = 150.0f;

const float mm_w = 400;

inline void AddVertex(std::vector <GLfloat>* a, Vec3 A) //check this!
{
    a->push_back(A[0]); a->push_back(A[1]); a->push_back(A[2]);
}

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

#ifndef GRAVITY
#define GRAVITY 9.7705078125
#endif

#endif