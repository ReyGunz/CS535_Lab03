#include "Wall.h"

Wall::Wall()
{
	init();
}

Wall::~Wall()
{
	vbo.deleet();
	vao.deleet();
}

void Wall::init()
{
	vao.bind();
	vbo.update(verts, sizeof(verts));
	vao.link_attribute(vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	vao.unbind();
	vbo.unbind();
}

void Wall::draw()
{
	vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}