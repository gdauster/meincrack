/* Copyright (c) 2016 Meincrack */
#include "Triangle.h"

Triangle::Triangle(Vector3 p1, Vector3 p2, Vector3 p3, GLfloat r, GLfloat g, GLfloat b) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->r = r;
	this->g = g;
	this->b = b;
	this->position = new Vector3();
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(LENGTH, Buffer);
	glBindBuffer(GL_ARRAY_BUFFER, Buffer[VERTICES]);

	GLfloat vertices[9] = {
		this->p1.getX(), this->p1.getY(), this->p1.getZ(),
		this->p2.getX(), this->p2.getY(), this->p2.getZ(),
		this->p3.getX(), this->p3.getY(), this->p3.getZ()
	};
	glBufferStorage(GL_ARRAY_BUFFER, sizeof(vertices), vertices, 0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
}

void Triangle::Draw()
{
	//glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();

	glTranslatef(position->getX(), position->getY(), position->getZ());

	glColor3f(r, g, b);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 9);

	//glPopMatrix();
}


