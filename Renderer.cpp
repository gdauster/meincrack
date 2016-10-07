/* Copyright (c) 2016 Meincrack */
#include "Renderer.h"

Renderer::Renderer() {}

void Renderer::render(Object3D o)
{
	glColor3f(o.r, o.g, o.b);
	glBindVertexArray(o.VAO);
	if (o.update)
	{
		glBindBuffer(GL_ARRAY_BUFFER, o.Buffer[o.VERTICES]);
		glBufferSubData(GL_ARRAY_BUFFER, 0, o.nbVertices * 3 * sizeof(GLfloat), o.vertices);
		o.update = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, o.nbVertices);
}

