#ifndef PATH_H
#define PATH_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Path {

public:
  Vec2f start, end;
  float radius;

  Path(Vec2f size) {
    radius = 20;
    start = Vec2f(0, size.y / 3);
    end = Vec2f(size.x, size.y * 2.0 / 3);
  }

  void draw() {
    gl::color(Color(0, 0, 0));
    gl::drawSolidRect(Rectf(start - Vec2f(-radius, 0), end + Vec2f(radius, 0)));
  }
};

#endif
