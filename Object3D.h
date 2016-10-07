/* Copyright (c) 2016 Meincrack */
#ifndef _OBJECT3D_H_
#define _OBJECT3D_H_

#include "main.h"
#include "Geometry.h"

class Object3D {

protected:
	// METHODS
	void _init();

public:
	// CONSTRUCTORS
	Object3D();

	// ATTRIBUTES
	enum _bufferIDs { VERTICES, LENGTH };
	GLuint Buffer[LENGTH];
	GLuint VAO;
	GLfloat* vertices;
	GLuint nbVertices;
	bool update = false;
	GLfloat r;
	GLfloat g;
	GLfloat b;
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	
};

#endif

