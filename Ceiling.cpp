#include "Ceiling.h"

Ceiling::Ceiling()
{
	init();
}

Ceiling::Ceiling(int w, int h)
{
	init(w, h);
}

Ceiling::~Ceiling()
{
	vbo.deleet();
	vao.deleet();
}

void Ceiling::init()
{
	vao.bind();
	vbo.update(verts, sizeof(verts));
	vao.link_attribute(vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	vao.unbind();
	vbo.unbind();
}

void Ceiling::init(int w, int h)
{
	GLfloat verts[42] = {
		-w,3.0,-h,	0.25,1,0.5,0.5,
		w,3.0,-h,	0.25,1,0.5,0.5,
		w,3.0,h,	0.25,1,0.5,0.5,
		-w,3.0,-h,	0.25,1,0.5,0.5,
		w,3.0,h,	0.25,1,0.5,0.5,
		-w,3.0,h,   0.25,1,0.5,0.5
	};

	vao.bind();
	vbo.update(verts, sizeof(verts));
	vao.link_attribute(vbo, 0, 3, GL_FLOAT, 7 * sizeof(float), (void*)0);
	vao.link_attribute(vbo, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.unbind();
	vbo.unbind();
}

void Ceiling::draw()
{
	vao.bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}