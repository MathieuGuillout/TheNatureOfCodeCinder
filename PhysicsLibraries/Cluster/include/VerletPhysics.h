#ifndef VERLET_PHYSICS_H
#define VERLET_PHYSICS_H

#include <list>
#include "cinder/app/AppBasic.h"
#include "VerletParticle.h"
#include "VerletSpring.h"
#include "ParticleBehavior.h"

class VerletPhysics {
private:
  float numIterations;
  float drag;
  float timeStep;

public:
  ci::Rectf bounds;
  std::list<ParticleBehavior *> behaviors;
  std::list<VerletParticle *> particles;
  std::list<VerletSpring *> springs;

  VerletPhysics();
  VerletPhysics(ci::Vec2f gravity, int numIterations, float drag, float timeStep);

  void setDrag(float drag);
  void update();
  void updateParticles();
  void updateSprings();
  void applyConstraints();
  void setWorldBounds(ci::Rectf _rect); 
  void addBehavior(ParticleBehavior * behavior);
  void addParticle(VerletParticle * particle);
  void addSpring(VerletSpring * spring);
};

#endif

