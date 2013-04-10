#include "VerletSpring.h"


VerletSpring::VerletSpring(VerletParticle * _a, VerletParticle * _b, float _len, float _strength) {
  a = _a;
  b = _b;
  restLength = _len;
  strength = _strength;
}

float VerletSpring::getRestLength() {
  return restLength;
}

float VerletSpring::getStrength() {
  return strength;
}

void VerletSpring::lockA(bool s) {
  isALocked = s;
}

void VerletSpring::lockB(bool s) {
  isBLocked = s;
}
  
void VerletSpring::setRestLength(float len) {
  restLength = len;
  restLengthSquared = len * len;
}

void VerletSpring::setStrength(float _strength){
  strength = _strength;
}

void VerletSpring::update(bool applyConstraints){
  ci::Vec2f delta = b->position - a->position;
  float dist = delta.length() + EPS;

  float normDistStrength = (dist - restLength) / (dist * (a->invWeight + b->invWeight)) * strength;

  if (!a->isLocked && !isALocked) {
    a->position += delta * (normDistStrength * a->invWeight);  
  }
              
  if (!b->isLocked && !isBLocked) {
    b->position += delta * (-normDistStrength * b->invWeight);  
  }
}

