#ifndef VERLET_GRAVITYBEHAVIOR_H
#define VERLET_GRAVITYBEHAVIOR_H

#include <list>
#include "cinder/app/AppBasic.h"
#include "ConstantForceBehavior.h"
#include "VerletParticle.h"

class GravityBehavior : public ConstantForceBehavior {
public:
  GravityBehavior(ci::Vec2f gravity);
  GravityBehavior(ci::Vec2f gravity, float timeStep);

  virtual void setForce(ci::Vec2f force);
};

#endif
