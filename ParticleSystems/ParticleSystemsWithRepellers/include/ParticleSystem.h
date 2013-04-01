#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "cinder/app/AppBasic.h"
#include <vector>
#include "Particle.h"
#include "Repeller.h"

class ParticleSystem {
private:
  std::vector<Particle *> particles;
  ci::Vec2f origin;
public:
  ParticleSystem(ci::Vec2f location);
  void addParticle();
  void update();
  void draw();
  void applyForce(ci::Vec2f force);
  void applyRepeller(Repeller * repeller);
};
#endif
