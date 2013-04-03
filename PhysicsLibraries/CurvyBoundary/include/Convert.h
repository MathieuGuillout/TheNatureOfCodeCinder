#ifndef CONVERT_H
#define CONVERT_H

#include "cinder/Vector.h"
#include <Box2D/Box2D.h>


class Convert {
public:
  static float getScaling() {
    return 50.0f;
  }

  static ci::Vec2f toScreen(b2Vec2 c) {
    return ci::Vec2f(c.x, c.y) * getScaling();
  }
  
  static b2Vec2 toPhysics(ci::Vec2f c) {
    return b2Vec2(c.x / getScaling(), c.y / getScaling());
  }

  static float toPhysics(float f) {
    return f / getScaling();
  }

  static float toScreen(float f) {
    return f * getScaling();
  }

  static float radToDeg(float rad) {
    return rad * 180.0f / M_PI;
  }

  static float degToRad(float deg) {
    return M_PI * deg  / 180.0f;
  }
};

#endif
