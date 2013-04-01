#ifndef PARTICLE_H
#define PARTICLE_H

#include "cinder/app/AppBasic.h"
#define LIFETIME 255

class Particle {
public:
  Particle(ci::Vec2f l);

  ci::Vec2f location;
  ci::Vec2f velocity;
  ci::Vec2f acceleration;
  float mass;
  float lifespan;

  virtual void draw();
  void applyForce(ci::Vec2f force);
  void update();
  bool isDead();
};
#endif
