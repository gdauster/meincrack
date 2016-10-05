/* Copyright (c) 2016 Meincrack */
#ifndef _SCENE_H_
#define _SCENE_H_

#include "main.h"
#include "Geometry.h"
#include "Triangle.h"

class Scene {

private:
	// ATRIBUTES
	Triangle* _triangle;

public:
	// CONSTRUCTORS
	Scene();
	
	// METHODS
	void DrawAll();
};

#endif