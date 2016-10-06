/* Copyright (c) 2016 Meincrack */
#include "Scene.h"

Scene::Scene() {
	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.39f, 0.58f, 0.93f, 1.f); //Specify values for later glClear() in main

	Vector3 p1(0.0f, 0.0f, 0.0f);
	Vector3 p2(0.0f, 0.5f, 0.0f);
	Vector3 p3(0.5f, 0.5f, 0.0f);
	Vector3 p4(-0.1f, 0.0f, 0.0f);
	Vector3 p5(-0.1f, 0.5f, 0.0f);
	Vector3 p6(-0.6f, -0.5f, 0.0f);

	_triangle1 = new Triangle(p1, p2, p3, 1.0f, 0.0f, 0.0f);
	_triangle2 = new Triangle(p4, p5, p6, 0.0f, 1.0f, 0.0f);
}

void Scene::DrawAll()
{
	//_triangle2->MoveRight();

	_triangle1->Draw();
	_triangle2->Draw();

	//_triangle1->MoveLeft();
}


