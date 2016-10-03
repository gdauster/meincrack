#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <GL/glew.h>

#ifdef __linux__
#elif _WIN32
#include <GL/wglew.h>
#include <Windows.h>
#endif

class Vector3 {
private:
  // ATTRIBUTES
  GLint _x;
  GLint _y;
  GLint _z;

public:
  // CONSTRUCTORS
  Vector3(const GLint x, const GLint y, const GLint z) { this->set(x, y, z); };
  Vector3(const Vector3& v) { this->set(v.getX(), v.getY(), v.getZ()); };
  Vector3() { this->set(0, 0, 0); };

  // GETTER SETTER
  const GLint getX() const { return _x; }
  const GLint getY() const { return _y; }
  const GLint getZ() const { return _z; }
  void setX(const GLint x) { _x = x; }
  void setY(const GLint y) { _y = y; }
  void setZ(const GLint z) { _z = z; }

  // METHODS
  void cpy(const Vector3& vector);
  void add(const Vector3& vector);
  void add(const GLint scalar);
  void sub(const Vector3& vector);
  void sub(const GLint scalar);
  void mul(const Vector3& vector);
  void mul(const GLint scalar);
  void div(const Vector3& vector);
  void div(const GLint scalar);
  void set(const GLint x, const GLint y, const GLint z);

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

  Vector3 operator+=(const GLint s) { this->add(s); return *this; }
  Vector3 operator+(const GLint s) {
    Vector3 w = Vector3(*this); w.add(s); return w; }
  Vector3 operator-=(const GLint s) { this->sub(s); return *this; }
  Vector3 operator-(const GLint s) {
    Vector3 w = Vector3(*this); w.sub(s); return w; }
  Vector3 operator*=(const GLint s) { this->mul(s); return *this; }
  Vector3 operator*(const GLint s) {
    Vector3 w = Vector3(*this); w.mul(s); return w; }
  Vector3 operator/=(const GLint s) { this->div(s); return *this; }
  Vector3 operator/(GLint s) {
    Vector3 w = Vector3(*this); w.div(s); return w; }
};

#endif
