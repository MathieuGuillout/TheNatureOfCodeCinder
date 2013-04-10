#ifndef VERLET_PARTICLE_H
#define VERLET_PARTICLE_H

#include <list>
#include "cinder/app/AppBasic.h"

class Behavior;

class VerletParticle {
private:
  bool isLocked;
  ci::Vec2f prev, temp;
  ci::Vec2f force;
  float weight;

public:
  ci::Vec2f position;
  std::list<Behavior *> behaviors;

  VerletParticle(ci::Vec2f _pos, float _weight = 1);
  void lock(); 
  void unlock();   
  void update();
  void applyBehaviors();
  void applyForce();
  void applyConstraints();
  void addForce(ci::Vec2f f);
};

#endif
