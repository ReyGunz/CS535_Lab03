#include "Sphere.h"

void Sphere::generate(int stacks, int slices, GLfloat r)
{
	Vec3 v;

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
			AddVertex(&vertex, v); //add the vertex
			glm::normalize(v);     //normalize it 
			AddVertex(&normal, v); //and add the normal vector
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
				r * sin(theta + deltaTheta) * sin(phi),
				r * cos(phi));
			AddVertex(&vertex, v); //add the vertex
			glm::normalize(v);     //normalize it 
			AddVertex(&normal, v); //and add the normal vector
			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
				r * sin(theta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			AddVertex(&vertex, v); //add the vertex
			glm::normalize(v);     //normalize it 
			AddVertex(&normal, v); //and add the normal vector
//the second triangle
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
				r * sin(theta + deltaTheta) * sin(phi),
				r * cos(phi));
			AddVertex(&vertex, v); //add the vertex
			glm::normalize(v);     //normalize it 
			AddVertex(&normal, v); //and add the normal vector
			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
				r * sin(theta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			AddVertex(&vertex, v); //add the vertex
			glm::normalize(v);     //normalize it 
			AddVertex(&normal, v); //and add the normal vector
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi + deltaPhi),
				r * sin(theta + deltaTheta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			AddVertex(&vertex, v); //add the vertex
			glm::normalize(v);     //normalize it 
			AddVertex(&normal, v); //and add the normal vector
		}
	}
}

void Sphere::init()
{
	points = vertex.size();
	normals = normal.size();

	glGenVertexArrays(1, &vao.ID);
	glBindVertexArray(vao.ID);

	vbo = new VBO(2);

	glGenBuffers(2, vbo->ID);
	GLuint vert_ID = vbo->ID[0];
	GLuint norm_ID = vbo->ID[1];

	glBindBuffer(GL_ARRAY_BUFFER, vert_ID);
	glBufferData(GL_ARRAY_BUFFER, points * sizeof(GLfloat), &vertex[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	vertex.clear();

	glBindBuffer(GL_ARRAY_BUFFER, norm_ID);
	glBufferData(GL_ARRAY_BUFFER, normals * sizeof(GLfloat), &normal[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	normal.clear(); //no need for the normal data, it is on the GPU now
}

Sphere::Sphere()
{
	generate(25,25,1.f);
	init();
}

void Sphere::draw()
{

}