//#version 330 core
//layout (location = 0) in vec4 aPos;
//uniform mat4 cam_M;
//void main()
//{
//vec4 oPos=cam_M*aPos;
//gl_Position = vec4(oPos.x, oPos.y, oPos.z, oPos.w);
//}

#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec3 aCol;

out vec4 color;

uniform mat4 cam_M;

void main()
{
vec4 oPos=cam_M*aPos;
gl_Position = vec4(oPos.x, oPos.y, oPos.z, oPos.w);
color = vec4(aCol,0.5);
}