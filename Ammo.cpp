#include "Ammo.h"

void Ammo::generate(int _stacks, int _slices, GLfloat _r)
{
	Vec3 v;
	Mat3 modely = Mat4(1.0);
	modely[0] = glm::vec3(2.0,0,0);

	std::cout << modely[0][0] << std::endl;

	GLfloat deltaTheta = 2 * M_PI / (GLfloat)slices;
	GLfloat deltaPhi = M_PI / (GLfloat)stacks;

	for (GLint i = 0; i < stacks; i++)
	{
		GLfloat phi = i * deltaPhi;
		for (GLint j = 0; j < slices; j++)
		{
			GLfloat theta = j * deltaTheta;
			//the first triangle
			v = glm::vec3(r * cos(theta) * sin(phi),
				r * sin(theta) * sin(phi),
				r * cos(phi));
			//glm::translate(modely, v);
			//glm::translate(Mat4(2.0), v);
			v.x += 10;
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
				r * sin(theta + deltaTheta) * sin(phi),
				r * cos(phi));
			//glm::translate(modely, v);
			//glm::translate(Mat4(2.0), v);
			v.x += 10;
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
				r * sin(theta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			//glm::translate(modely, v);
			//glm::translate(Mat4(2.0), v);
			v.x += 10;
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
//the second triangle
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
				r * sin(theta + deltaTheta) * sin(phi),
				r * cos(phi));
			//glm::translate(modely, v);
			//glm::translate(Mat4(2.0), v);
			v.x += 10;
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
				r * sin(theta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			//glm::translate(modely, v);
			//glm::translate(Mat4(2.0), v);
			v.x += 10;
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi + deltaPhi),
				r * sin(theta + deltaTheta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			//glm::translate(modely, v);
			//glm::translate(Mat4(2.0), v);
			v.x += 10;
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
		}
	}

	std::cout << "sphere vert size: " << verts.size() << std::endl;
}

void Ammo::init()
{
	points = verts.size();
	normals = colors.size();

	//get the vertex array handle and bind it
	glGenVertexArrays(1, &vao.ID);
	glBindVertexArray(vao.ID);

	//vbo = new VBO(2);
	//the vertex array will have two vbos, vertices and normals
	glGenBuffers(2, vbo.ID);
	GLuint verticesID = vbo.ID[0];
	GLuint colorsID = vbo.ID[1];

	//send vertices
	glBindBuffer(GL_ARRAY_BUFFER, verticesID);
	glBufferData(GL_ARRAY_BUFFER, points * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	////send color
	//glBindBuffer(GL_ARRAY_BUFFER, verticesID);
	//glBufferData(GL_ARRAY_BUFFER, points * sizeof(GLfloat), &verts[0], GL_STATIC_DRAW);
	//glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//glEnableVertexAttribArray(0);
	verts.clear(); //no need for the vertex data, it is on the GPU now

//send colors
	glBindBuffer(GL_ARRAY_BUFFER, colorsID);
	glBufferData(GL_ARRAY_BUFFER, normals * sizeof(GLfloat), &colors[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	colors.clear(); //no need for the normal data, it is on the GPU now
}

Ammo::Ammo()
{
	generate(25, 25, 10.f);
	init();
}

Ammo::~Ammo()
{
	//delete vbo;
}

void Ammo::draw()
{

	int factor = 3 * points;
	vao.bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPointSize(5.0f);
	glLineWidth(1.0f);
	glDrawArrays(GL_POINTS, 0, factor);
	glDrawArrays(GL_LINE_STRIP, 0, factor);
}