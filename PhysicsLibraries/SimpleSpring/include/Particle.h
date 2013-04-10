#ifndef BALL_H
#define BALL_H

#include "cinder/app/AppBasic.h"
#include "VerletPhysics.h"

using namespace ci;

class Particle : public VerletParticle {
public:
  Particle(Vec2f pos);
  void draw();
};
#endif
