/* Copyright (c) 2016 Minecrack */
#include "Geometry.h"

void Vector3::set(const GLint x, const GLint y, const GLint z) {
  _x = x;
  _y = y;
  _z = z;
}
void Vector3::cpy(const Vector3& vector) {
  _x = vector.getX();
  _y = vector.getY();
  _z = vector.getZ();
}

void Vector3::add(const Vector3& vector) {
  _x += vector.getX();
  _y += vector.getY();
  _z += vector.getZ();
}
void Vector3::sub(const Vector3& vector) {
  _x -= vector.getX();
  _y -= vector.getY();
  _z -= vector.getZ();
}
void Vector3::mul(const Vector3& vector) {
  _x *= vector.getX();
  _y *= vector.getY();
  _z *= vector.getZ();
}
void Vector3::div(const Vector3& vector) {
  _x /= vector.getX();
  _y /= vector.getY();
  _z /= vector.getZ();
}

void Vector3::add(const GLint scalar) {
  _x += scalar;
  _y += scalar;
  _z += scalar;
}
void Vector3::sub(const GLint scalar) {
  _x -= scalar;
  _y -= scalar;
  _z -= scalar;
}
void Vector3::mul(const GLint scalar) {
  _x *= scalar;
  _y *= scalar;
  _z *= scalar;
}
void Vector3::div(const GLint scalar) {
  _x /= scalar;
  _y /= scalar;
  _z /= scalar;
}
