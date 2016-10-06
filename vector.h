#ifndef _VEC_H_
#define _VEC_H_

class Vector2 {
private:

public:
  GLfloat x;
  GLfloat y;

  Vector2(const GLfloat x, const GLfloat y) { x(x); y(y) };
  Vector2() { x(0); y(0) };
  Vector2(const Vector2& vector) {  };


}

#endif
