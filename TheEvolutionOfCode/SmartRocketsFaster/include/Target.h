#ifndef TARGET_H
#define TARGET_H

#include "cinder/Vector.h"

class Target {
public:
  ci::Vec2f position;
  float radius;

  Target(ci::Vec2f pos, float r);
  void draw();
};

#endif
