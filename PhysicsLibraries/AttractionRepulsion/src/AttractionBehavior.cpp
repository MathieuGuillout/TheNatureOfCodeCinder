#include "AttractionBehavior.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;

AttractionBehavior::AttractionBehavior(VerletParticle * _attractor, float _radius, float _strength, float _jitter) {
  attractor = _attractor;
  strength = _strength;
  jitter = _jitter;

  timeStep = 0;
  attrStrength = 0;

  setRadius(_radius);
}

void AttractionBehavior::apply(VerletParticle * p) {
  Vec2f delta = attractor->position - p->position;
  float dist = delta.lengthSquared();
  if (dist < radiusSquared) {
    Vec2f f = delta.safeNormalized() * (1.0f - dist / radiusSquared);
    f += Rand::randVec2f() * jitter;
    f *= attrStrength;
    p->addForce(f);
  }
}

void AttractionBehavior::configure(float _timeStep) {
  timeStep = _timeStep;
  setStrength(strength);
}

VerletParticle * AttractionBehavior::getAttractor()  {
  return attractor;
}

float AttractionBehavior::getJitter() {
  return jitter;
}

float AttractionBehavior::getStrength() {
  return strength;
}

void AttractionBehavior::setAttractor(VerletParticle * _attractor) {
  attractor = _attractor;
}

void AttractionBehavior::setJitter(float _jitter) {
  jitter = _jitter;
}

void AttractionBehavior::setRadius(float r) {
  radius = r;
  radiusSquared = r * r;
}

void AttractionBehavior::setStrength(float _strength) {
  strength = _strength;
  attrStrength = strength * timeStep;
}
