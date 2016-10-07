/* Copyright (c) 2016 Meincrack */
#include "Triangle.h"

#include <iostream>
using std::cout;
using std::endl;

Triangle::Triangle(Vector3 p1, Vector3 p2, Vector3 p3,
                  GLfloat r, GLfloat g, GLfloat b) {
  this->p1 = p1;
  this->p2 = p2;
  this->p3 = p3;
  this->r = r;
  this->g = g;
  this->b = b;
  this->position = new Vector3();
	glEnable(GL_TEXTURE_2D);

  _vertices = new GLfloat[9] {
    this->p1.getX(), this->p1.getY(), this->p1.getZ(),
    this->p2.getX(), this->p2.getY(), this->p2.getZ(),
    this->p3.getX(), this->p3.getY(), this->p3.getZ()
  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(LENGTH, Buffer);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, Buffer[VERTICES]);
  glBufferStorage(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), _vertices, 0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  glEnableVertexAttribArray(0);

  _program = glCreateProgram();
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
}

void Triangle::Draw() {
  glColor3f(r, g, b);
  glBindVertexArray(VAO);

  // glBindBuffer(GL_ARRAY_BUFFER, Buffer[VERTICES]);
  // glBufferStorage(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), _vertices, 0);

  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  // glEnableVertexAttribArray(0);

  glDrawArrays(GL_TRIANGLES, 0, 9);
}

void Triangle::MoveLeft() {
  // glTranslatef(0.01f, 0.0f, 0.0f);
  _vertices[0] = 0.01f;
  _vertices[1] = 0.01f;
  _vertices[2] = 0.01f;

  cout << "(" << _vertices[0] << ";" << _vertices[1]
    << ";" << _vertices[2] << ")" << endl;
}

void Triangle::MoveRight() {
  // glTranslatef(-0.01f, 0.0f, 0.0f);
  this->_vertices[0] -= 0.01f;
  this->_vertices[3] -= 0.01f;
  this->_vertices[6] -= 0.01f;
}
