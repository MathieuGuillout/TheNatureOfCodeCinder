#ifndef VERLET_SPRING_H
#define VERLET_SPRING_H

#include <list>
#include "cinder/app/AppBasic.h"

#include "VerletParticle.h"

 const static float EPS = 1e-6f;

class VerletSpring {
private:

  VerletParticle * a;
  VerletParticle * b;
  float restLength, restLengthSquared;
  float strength;
  bool isALocked, isBLocked;
public:
  VerletSpring(VerletParticle * _a, VerletParticle * _b, float _len, float _strength);
  float getRestLength();
  float getStrength();
  void lockA(bool s);
  void lockB(bool s);
  void setRestLength(float len);
  void setStrength(float strength);
  void update(bool applyConstraints);
};

#endif
