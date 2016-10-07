/* Copyright (c) 2016 Meincrack */
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "main.h"
#include "Geometry.h"
#include "Object3D.h"

class Renderer {
private:
public:
	Renderer();
	void render(Object3D obj);
};

#endif