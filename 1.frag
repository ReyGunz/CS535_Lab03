//#version 330 core
//out vec4 col;
//uniform vec4 color;
//void main()
//{
//  col = color;
//}

#version 330 core
out vec4 col;

in vec4 color;

void main()
{
 col = color;
}