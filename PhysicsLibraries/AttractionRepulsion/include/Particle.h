#ifndef BALL_H
#define BALL_H

#include "cinder/app/AppBasic.h"
#include "VerletPhysics.h"

using namespace ci;

class Particle : public VerletParticle {
public:
  float radius;
  Particle(Vec2f pos, float _radius);
  void draw();
};
#endif
