#ifndef PAIR_H
#define PAIR_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"
#include "Particle.h"

class Pair {
private:
  Particle * p1;
  Particle * p2;
  float len;

public:
  Pair(b2World * world, ci::Vec2f pos, float radius);
  void draw();
  void update();
};

#endif
