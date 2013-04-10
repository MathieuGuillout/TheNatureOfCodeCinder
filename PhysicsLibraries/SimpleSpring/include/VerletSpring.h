#ifndef VERLET_SPRING_H
#define VERLET_SPRING_H

#include <list>
#include "cinder/app/AppBasic.h"

#include "VerletParticle.h"

class VerletSpring {
private:
  VerletParticle * p1;
  VerletParticle * p2;
  float len;
  float strength;
public:
  VerletSpring(VerletParticle * _p1, VerletParticle * _p2, float _len, float _strength) {
    p1 = _p1;
    p2 = _p2;
    len = _len;
    strength = _strength;
  }
};

#endif
