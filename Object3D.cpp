/* Copyright (c) 2016 Meincrack */
#include "Object3D.h"

Object3D::Object3D()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(LENGTH, Buffer);
}

void Object3D::_init()
{
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, Buffer[VERTICES]);
	glBufferStorage(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertices, GL_DYNAMIC_STORAGE_BIT);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0); //Unbind VAO

	/* _program = glCreateProgram();
	const GLchar* vertex_shader =
	"                "
	"#version 400 core        "
	"                "
	"uniform  vec4  vPosition;      "
	"                "
	"void main()          "
	"{                "
	"  vec4  pos = vec4( 0.0 );"
	"  gl_Position = pos;  "
	"}                "
	"";
	GLuint shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader, 1, &vertex_shader, NULL);
	glCompileShader(shader);
	glAttachShader(_program, shader);
	glLinkProgram(_program);
	glUseProgram(_program);

	GLuint vPosition = glGetUniformLocation(_program, "vPosition");
	GLfloat* params1;
	glUniform4f(vPosition, 0.6f, 0.0f, 0.0f, 1.0f);
	glGetUniformfv(_program, vPosition, params1);
	cout << params1[0] << " " << params1[1] << " " << params1[2] << " " << params1[3] << " yo" << endl;
	*/
}
