#include "Shape.h"

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(int stacks, int slices, GLfloat r);

	virtual void draw();

private:
	GLuint stacks, slices;
	GLfloat r;

	void generate(int stacks, int slices, GLfloat r);
	void init();
	void generate();
	//void draw();
};