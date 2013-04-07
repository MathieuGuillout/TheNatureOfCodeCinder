#ifndef PARTICLE_H
#define PARTICLE_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"

class Particle {
private:
  float radius;
  b2World * world;

public:
  Particle(b2World * world, ci::Vec2f position, float radius);
  b2Body * body;
  ci::Vec2f position;
  void draw();
  void update();
  void killBody();
};

#endif
