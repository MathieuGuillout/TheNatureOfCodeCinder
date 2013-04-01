#ifndef PARTICLE_H;
#define PARTICLE_H

#include "cinder/app/AppBasic.h"

class Particle {
private:
  ci::Vec2f location;
  ci::Vec2f velocity;
  ci::Vec2f acceleration;
  float lifespan;
public:
  Particle(ci::Vec2f l);
  void draw();
  void update();
  bool isDead();
};
#endif
