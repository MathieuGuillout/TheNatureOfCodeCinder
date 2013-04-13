#ifndef TARGET_H
#define TARGET_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;

class Target {
private:
  float radius;
public:
  Vec2f position;
  Target(Vec2f _position, float _radius) {
    position = _position;
    radius = _radius;
  }
  void draw() {
    color(Color(0, 0, 0));
    drawSolidCircle(position, radius);
  }
};

#endif
