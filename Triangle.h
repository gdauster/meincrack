/* Copyright (c) 2016 Meincrack */
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "main.h"
#include "Geometry.h"

class Triangle {

private:
	// ATTRIBUTES
	const enum _bufferIDs { VERTICES, COLORS, LENGTH };

public:
	// CONSTRUCTORS
	Triangle(Vector3 p1, Vector3 p2, Vector3 p3, GLfloat r, GLfloat g, GLfloat b);

	// ATTRIBUTES
	GLfloat r;
	GLfloat g;
	GLfloat b;
	Vector3 p1;
	Vector3 p2;
	Vector3 p3;
	GLuint Buffer[LENGTH];
	GLuint VAO;
	Vector3* position;

	// METHODS
	void Draw();
};

#endif