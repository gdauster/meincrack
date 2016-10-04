/* Copyright (c) 2016 Meincrack */
#ifndef _BOX_H_
#define _BOX_H_

#include "main.h"
#include "Geometry.h"

class Box {
private:
	// ATTRIBUTES
	GLfloat _width;
	GLfloat _height;
	GLfloat _depth;
	Vector3 _position;
	Vector3 _scale;
	Vector3 _rotation;

public:
	// CONSTRUCTORS
	Box();

	// GETTER SETTER
	const GLfloat getWidth() const { return _width; }
	const GLfloat getHeight() const { return _height; }
	const GLfloat getDepth() const { return _depth; }
	const Vector3 getPosition() const { return _position; }
	const Vector3 getScale() const { return _scale; }
	const Vector3 getRotation() const { return _rotation; }
	void setPosition(const Vector3& position) { _position.cpy(position); }
	void setScale(const Vector3& scale) { _scale.cpy(scale); }
	void setRotation(const Vector3& rotation) { _rotation.cpy(rotation); }
};


#endif