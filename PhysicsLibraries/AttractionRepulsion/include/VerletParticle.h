#ifndef VERLET_PARTICLE_H
#define VERLET_PARTICLE_H

#include <list>
#include "cinder/app/AppBasic.h"

class Behavior;

class VerletParticle {
private:
  ci::Vec2f prev, temp;
  ci::Vec2f force;

public:
  ci::Vec2f position;
  float weight, invWeight;
  bool isLocked;
  std::list<Behavior *> behaviors;

  VerletParticle(ci::Vec2f _pos, float _weight = 1);
  void lock(); 
  void setWeight(float weight);
  void unlock();   
  void update();
  void applyBehaviors();
  void applyForce();
  void applyConstraints();
  void addForce(ci::Vec2f f);
  void scaleVelocity(float scl);
};

#endif
