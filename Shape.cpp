#include "Shape.h"

//void Shape::set_position(Vec3 _position)
//{
//	//p = _position;
//}

void Shape::set_color(GLubyte r, GLubyte b, GLubyte g)
{
	color[0] = r; color[1] = b; color[2] = g;
}

void Shape::set_model(Mat4 tmp)
{
	model = tmp;
}

void Shape::set_model_view_n(Mat3 tmp)
{
	model_view_n = tmp;
}

void Shape::draw()
{
	std::cout << "cannot render shape" << std::endl;
}