#ifndef PARTICLESYSTEM_H;
#define PARTICLESYSTEM_H

#include "cinder/app/AppBasic.h"
#include <vector>
#include "Particle.h"

class ParticleSystem {
private:
  std::vector<Particle *> particles;
  ci::Vec2f origin;
public:
  ParticleSystem(ci::Vec2f location);
  void addParticle();
  void update();
  void draw();
};
#endif
