/* Copyright (c) 2016 Meincrack */
#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "main.h"

class Vector3 {
private:
  // ATTRIBUTES
  GLfloat _x;
  GLfloat _y;
  GLfloat _z;

public:
  // CONSTRUCTORS
  Vector3(const GLfloat x, const GLfloat y, const GLfloat z) {
	  this->set(x, y, z); 
  };
  Vector3(const Vector3& v) { this->set(v.getX(), v.getY(), v.getZ()); };
  Vector3() { this->set(0, 0, 0); };

  // GETTER SETTER
  const GLfloat getX() const { return _x; }
  const GLfloat getY() const { return _y; }
  const GLfloat getZ() const { return _z; }
  void setX(const GLfloat x) { _x = x; }
  void setY(const GLfloat y) { _y = y; }
  void setZ(const GLfloat z) { _z = z; }
  void set(const GLfloat x, const GLfloat y, const GLfloat z);

  // METHODS
  void cpy(const Vector3& vector);
  void add(const Vector3& vector);
  void add(const GLfloat scalar);
  void sub(const Vector3& vector);
  void sub(const GLfloat scalar);
  void mul(const Vector3& vector);
  void mul(const GLfloat scalar);
  void div(const Vector3& vector);
  void div(const GLfloat scalar);

  // OPERATORS
  Vector3 operator+=(const Vector3& v) { this->add(v); return *this; }
  Vector3 operator+(const Vector3& v) {
    Vector3 w = Vector3(*this); w.add(v); return w; }
  Vector3 operator-=(const Vector3& v) { this->sub(v); return *this; }
  Vector3 operator-(const Vector3& v) {
    Vector3 w = Vector3(*this); w.sub(v); return w; }
  Vector3 operator*=(const Vector3& v) { this->mul(v); return *this; }
  Vector3 operator*(const Vector3& v) {
    Vector3 w = Vector3(*this); w.mul(v); return w; }
  Vector3 operator/=(const Vector3& v) { this->div(v); return *this; }
  Vector3 operator/(const Vector3& v) {
    Vector3 w = Vector3(*this); w.div(v); return w; }

  Vector3 operator+=(const GLfloat s) { this->add(s); return *this; }
  Vector3 operator+(const GLfloat s) {
    Vector3 w = Vector3(*this); w.add(s); return w; }
  Vector3 operator-=(const GLfloat s) { this->sub(s); return *this; }
  Vector3 operator-(const GLfloat s) {
    Vector3 w = Vector3(*this); w.sub(s); return w; }
  Vector3 operator*=(const GLfloat s) { this->mul(s); return *this; }
  Vector3 operator*(const GLfloat s) {
    Vector3 w = Vector3(*this); w.mul(s); return w; }
  Vector3 operator/=(const GLfloat s) { this->div(s); return *this; }
  Vector3 operator/(GLfloat s) {
    Vector3 w = Vector3(*this); w.div(s); return w; }
};

#endif
