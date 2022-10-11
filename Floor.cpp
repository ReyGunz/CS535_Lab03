#include "Floor.h"

Floor::Floor()
{
	init();
}

Floor::Floor(int w, int h)
{
	this->color = Color3(1, 0.5, 0.25);
	init(w, h);
}

Floor::~Floor()
{
	vbo.deleet();
	vao.deleet();
}


void Floor::init(int w, int h)
{
	int min = -w, max = w;
	int w_step = 2 * w / (t_steps - 1), h_step = 2 * h / (t_steps - 1);

	//for (int i = 0; i < t_steps - 1; i++)
	//{
	//	for (int j = 0; j < t_steps; j++)
	//	{
	//		Vec3 vy = Vec3(min + j * w_step, -1.0f, min + i * w_step);
	//		AddVertex(&verts2, vy);
	//		AddVertex(&verts2, color);

	//		Vec3 vx = Vec3(min + (j + 1) * w_step, -1.0f, min + i * w_step);
	//		AddVertex(&verts2, vx);
	//		AddVertex(&verts2, color);

	//		Vec3 vz = Vec3(min + (j + 1) * w_step, -1.0f, min + (i + 1) * w_step);
	//		AddVertex(&verts2, vz);
	//		AddVertex(&verts2, color);

	//	}
	//}

	for (int i = 0; i < t_steps - 1; i++)
	{
		//Vec3 vx = Vec3(min + i * w_step, -1.0f, 0.0f);
		//AddVertex(&verts2, vx);
		//AddVertex(&verts2, color);

		//Vec3 vy = Vec3(min + (i + 1) * w_step, -1.0f, 0.0f);
		//AddVertex(&verts2, vy);
		//AddVertex(&verts2, color);

		for (int j = 0; j < t_steps - 1; j++)
		{
			//Vec3 v1 = Vec3(min + j * w_step, -1.0f, min + (i + 1) * w_step);
			//Vec3 v2 = Vec3(min + j * w_step, -1.0f, min + i * w_step);
			//Vec3 v3 = Vec3(min + (j + 1) * w_step, -1.0f, min + i * w_step);
			//Vec3 v4 = Vec3(min + (j + 1) * w_step, -1.0f, min + (i + 1) * w_step);

			//AddVertex(&verts2, v1);
			//AddVertex(&verts2, color);
			//AddVertex(&verts2,v2);
			//AddVertex(&verts2, color);
			//AddVertex(&verts2, v3);
			//AddVertex(&verts2, color);
			//AddVertex(&verts2, v1);
			//AddVertex(&verts2, color);
			//AddVertex(&verts2, v4);
			//AddVertex(&verts2, color);
			//{

				//Vec3 v4 = Vec3(min + (i + 1) * w_step, -1.0f, min + (j + 1) * w_step);
				//AddVertex(&verts2, v4);
				//AddVertex(&verts2, color);

				Vec3 v2 = Vec3(min + j * w_step, -1.0f, min + i * w_step);
				AddVertex(&verts2, v2);
				AddVertex(&verts2, color);

				Vec3 v3 = Vec3(min + j * w_step, -1.0f, min + (i + 1) * w_step);
				AddVertex(&verts2, v3);
				AddVertex(&verts2, color);

				//Vec3 v2 = Vec3(min + j * w_step, -1.0f, min + i * w_step);
				//AddVertex(&verts2, v2);
				//AddVertex(&verts2, color);
			//}

			////AddVertex(&verts2, v2);
			////AddVertex(&verts2, color);

			//Vec3 v4 = Vec3(min + (i + 1) * w_step, -1.0f, min + (j + 1) * w_step);
			//AddVertex(&verts2, v4);
			//AddVertex(&verts2, color);

			//////Vec3 v2 = Vec3(min + i * w_step, -1.0f, min + j * w_step);
			////AddVertex(&verts2, v2);
			////AddVertex(&verts2, color);

		}
	}



	points = verts2.size();
	std::cout << points << std::endl;

	vao.bind();
	vbo.update(&verts2[0], points * sizeof(GLfloat));
	vao.link_attribute(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	vao.link_attribute(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	vao.unbind();
	vbo.unbind();
}

void Floor::init()
{
	vao.bind();
	vbo.update(&verts2[0], 60 * sizeof(GLfloat));
	vao.link_attribute(vbo, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	vao.unbind();
	vbo.unbind();
}

void Floor::draw()
{
	int factor = points/6;
	vao.bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPointSize(5.0f);
	glLineWidth(1.0f);
	glDrawArrays(GL_POINTS, 0, factor);
	glDrawArrays(GL_LINE_STRIP, 0, factor);
	//glDrawArrays(GL_POINTS, 7, 1);
	//glDrawArrays(GL_POINTS, 14, 1);
	//glDrawArrays(GL_POINTS, 21, 1);
	//glDrawArrays(GL_POINTS, 28, 1);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	//glDrawArrays(GL_LINE_STRIP, 0, 1);
	//glDrawArrays(GL_LINE_STRIP, 7, 1);
	//glDrawArrays(GL_LINE_STRIP, 0, points);
}