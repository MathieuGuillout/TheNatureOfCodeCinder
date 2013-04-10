#ifndef VERLET_BEHAVIOR_H
#define VERLET_BEHAVIOR_H

#include <list>
#include "cinder/app/AppBasic.h"

#include "VerletParticle.h"

class ParticleBehavior {
public:
  virtual void apply(VerletParticle * p) {};
  virtual void configure(float timeStep) {};
};

#endif
