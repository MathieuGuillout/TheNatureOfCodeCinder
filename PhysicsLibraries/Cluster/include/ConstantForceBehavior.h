#ifndef CONSTANT_FORCE_BEHAVIOR_H
#define CONSTANT_FORCE_BEHAVIOR_H

#include <list>
#include "cinder/app/AppBasic.h"

#include "VerletParticle.h"
#include "ParticleBehavior.h"

class ConstantForceBehavior : public ParticleBehavior{
public:
  float timeStep;
  ci::Vec2f force;
  ci::Vec2f scaledForce;

  ConstantForceBehavior(ci::Vec2f force);

  virtual void apply(VerletParticle * p);
  virtual void setForce(ci::Vec2f force);
  ci::Vec2f getForce();
  void configure(float timeStep);
};

#endif
