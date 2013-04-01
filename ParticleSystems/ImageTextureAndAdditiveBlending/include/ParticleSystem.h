#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include <list>
#include "Particle.h"

class ParticleSystem {
private:
  std::list<Particle *> particles;
  ci::Vec2f origin;
  ci::gl::Texture myTexture;
public:
  ParticleSystem(ci::Vec2f location, ci::gl::Texture text);
  void addParticle();
  void update();
  void draw();
  void applyForce(ci::Vec2f force);
};
#endif
