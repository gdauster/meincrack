/* Copyright (c) 2016 Meincrack */
#include "Triangle.h"

#include <iostream>
using std::cout;
using std::endl;

Triangle::Triangle(Vector3 p1, Vector3 p2, Vector3 p3,
                  GLfloat r, GLfloat g, GLfloat b) {
  this->r = r;
  this->g = g;
  this->b = b;
  
  vertices = new GLfloat[9] {
    p1.getX(), p1.getY(), p1.getZ(),
    p2.getX(), p2.getY(), p2.getZ(),
    p3.getX(), p3.getY(), p3.getZ()
  };
  nbVertices = 9;

  _init();
}

