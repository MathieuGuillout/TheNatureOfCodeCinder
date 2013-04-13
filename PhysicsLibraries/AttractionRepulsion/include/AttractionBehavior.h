#ifndef ATTRACTION_BEHAVIOR_H
#define ATTRACTION_BEHAVIOR_H

#include <list>
#include "cinder/app/AppBasic.h"
#include "ParticleBehavior.h"
#include "VerletParticle.h"

class AttractionBehavior : public ParticleBehavior {
private:
  VerletParticle * attractor;
  float attrStrength;

  float radius, radiusSquared;
  float strength;
  float jitter;
  float timeStep;

public:
  AttractionBehavior(VerletParticle * attractor, float radius, float strength, float jitter=0);
  void apply(VerletParticle * p);
  void configure(float timeStep);
  
  VerletParticle * getAttractor();
  float getJitter();
  float getRadius();
  float getStrength();

  void setAttractor(VerletParticle * attractor);
  void setJitter(float jitter);
  void setRadius(float r);
  void setStrength(float strength);
};

#endif
