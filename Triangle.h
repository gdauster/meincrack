/* Copyright (c) 2016 Meincrack */
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "main.h"
#include "Geometry.h"
#include "Object3D.h"

class Triangle : Object3D {

private:
	// ATTRIBUTES

public:
	// CONSTRUCTORS
	Triangle(Vector3 p1, Vector3 p2, Vector3 p3, GLfloat r, GLfloat g, GLfloat b);

	// ATTRIBUTES
	
	// METHODS
};

#endif
