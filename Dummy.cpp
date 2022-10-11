#include "Dummy.h"
//#include "Dummy.h"
//
//Dummy::Dummy()
//{
//	generate(55, 55, 1.f);
//	init_arrays();
//}
//
//Dummy::Dummy(int stacks, int slices, GLfloat r)
//{
//	this->stacks = stacks;
//	this->slices = slices;
//	this->r = r;
//	generate(stacks, slices, r);
//	init_arrays();
//}
//
//void Dummy::init_arrays()
//{
//	points = vertex.size();
//	normals = normal.size();
//
//	//get the vertex array handle and bind it
//	glGenVertexArrays(1, &vaID);
//	glBindVertexArray(vaID);
//
//	//the vertex array will have two vbos, vertices and normals
//	glGenBuffers(2, vboHandles);
//	GLuint verticesID = vboHandles[0];
//	GLuint normalsID = vboHandles[1];
//
//	//send vertices
//	glBindBuffer(GL_ARRAY_BUFFER, verticesID);
//	glBufferData(GL_ARRAY_BUFFER, points * sizeof(GLfloat), &vertex[0], GL_STATIC_DRAW);
//	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(0);
//	vertex.clear(); //no need for the vertex data, it is on the GPU now
//
////send normals
//	glBindBuffer(GL_ARRAY_BUFFER, normalsID);
//	glBufferData(GL_ARRAY_BUFFER, normals * sizeof(GLfloat), &normal[0], GL_STATIC_DRAW);
//	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
//	glEnableVertexAttribArray(1);
//	normal.clear(); //no need for the normal data, it is on the GPU now
//}
//
//void Dummy::generate(int stacks, int slices, GLfloat r)
//{
//	glm::vec3 v;
//
//	GLfloat deltaTheta = 2 * M_PI / (GLfloat)slices;
//	GLfloat deltaPhi = M_PI / (GLfloat)stacks;
//
//	for (GLint i = 0; i < stacks; i++)
//	{
//		GLfloat phi = i * deltaPhi;
//		for (GLint j = 0; j < slices; j++)
//		{
//			GLfloat theta = j * deltaTheta;
//			//the first triangle
//			v = glm::vec3(r * cos(theta) * sin(phi),
//				r * sin(theta) * sin(phi),
//				r * cos(phi));
//			AddVertex(&vertex, &v); //add the vertex
//			glm::normalize(v);     //normalize it 
//			AddVertex(&normal, &v); //and add the normal vector
//			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
//				r * sin(theta + deltaTheta) * sin(phi),
//				r * cos(phi));
//			AddVertex(&vertex, &v); //add the vertex
//			glm::normalize(v);     //normalize it 
//			AddVertex(&normal, &v); //and add the normal vector
//			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
//				r * sin(theta) * sin(phi + deltaPhi),
//				r * cos(phi + deltaPhi));
//			AddVertex(&vertex, &v); //add the vertex
//			glm::normalize(v);     //normalize it 
//			AddVertex(&normal, &v); //and add the normal vector
////the second triangle
//			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
//				r * sin(theta + deltaTheta) * sin(phi),
//				r * cos(phi));
//			AddVertex(&vertex, &v); //add the vertex
//			glm::normalize(v);     //normalize it 
//			AddVertex(&normal, &v); //and add the normal vector
//			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
//				r * sin(theta) * sin(phi + deltaPhi),
//				r * cos(phi + deltaPhi));
//			AddVertex(&vertex, &v); //add the vertex
//			glm::normalize(v);     //normalize it 
//			AddVertex(&normal, &v); //and add the normal vector
//			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi + deltaPhi),
//				r * sin(theta + deltaTheta) * sin(phi + deltaPhi),
//				r * cos(phi + deltaPhi));
//			AddVertex(&vertex, &v); //add the vertex
//			glm::normalize(v);     //normalize it 
//			AddVertex(&normal, &v); //and add the normal vector
//		}
//	}
//}
//
//void Dummy::draw()
//{
//	//glBindVertexArray(vaID);
//	////	glBindBuffer(GL_ARRAY_BUFFER, buffer);
//	////	glEnableVertexAttribArray(0);
//	//	//material properties
//	//glUniform3fv(kaParameter, 1, glm::value_ptr(ka));
//	//glUniform3fv(kdParameter, 1, glm::value_ptr(kd));
//	//glUniform3fv(ksParameter, 1, glm::value_ptr(ks));
//	//glUniform1fv(shParameter, 1, &sh);
//	////model matrix
//	//glUniformMatrix4fv(modelParameter, 1, GL_FALSE, glm::value_ptr(model));
//	////model for normals
//	//glUniformMatrix3fv(modelViewNParameter, 1, GL_FALSE, glm::value_ptr(modelViewN));
//	//glDrawArrays(GL_TRIANGLES, 0, 3 * points);
//}

void Dummy::generate(int _stacks, int _slices, GLfloat _r)
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
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
				r * sin(theta + deltaTheta) * sin(phi),
				r * cos(phi));
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
				r * sin(theta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
//the second triangle
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi),
				r * sin(theta + deltaTheta) * sin(phi),
				r * cos(phi));
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta) * sin(phi + deltaPhi),
				r * sin(theta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
			v = glm::vec3(r * cos(theta + deltaTheta) * sin(phi + deltaPhi),
				r * sin(theta + deltaTheta) * sin(phi + deltaPhi),
				r * cos(phi + deltaPhi));
			AddVertex(&verts, v); //add the vertex
			glm::normalize(v);     //normalize it 
			//AddVertex(&normal, &v); //and add the normal vector
			AddVertex(&colors, color); //add the vertex
		}
	}

	std::cout << "sphere vert size: " << verts.size() << std::endl;
}

void Dummy::init()
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

Dummy::Dummy()
{
	generate(25, 25, 10.f);
	init();
}

Dummy::~Dummy()
{
	//delete vbo;
}

void Dummy::draw()
{

	int factor = 3 * points;
	vao.bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPointSize(5.0f);
	glLineWidth(1.0f);
	glDrawArrays(GL_POINTS, 0, factor);
	glDrawArrays(GL_LINE_STRIP, 0, factor);
}