#ifndef PARTICLE_H
#define PARTICLE_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"
#define LIFETIME 512

class Particle {
public:
  Particle(ci::Vec2f l, ci::gl::Texture text);

  ci::Vec2f location;
  ci::Vec2f velocity;
  ci::Vec2f acceleration;
  ci::gl::Texture myTexture;
  float mass;
  float lifespan;

  virtual void draw();
  void applyForce(ci::Vec2f force);
  void update();
  bool isDead();
};
#endif
