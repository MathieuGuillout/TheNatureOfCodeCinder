#include "ConstantForceBehavior.h"

ConstantForceBehavior::ConstantForceBehavior(ci::Vec2f _force) {
  force = _force; 
  scaledForce = ci::Vec2f(0, 0);
}

void ConstantForceBehavior::apply(VerletParticle * p) {
  //ci::app::console() << scaledForce << std::endl;
  p->addForce(scaledForce);
}

void ConstantForceBehavior::configure(float _timeStep) {
  timeStep = _timeStep;
  setForce(force);
}

ci::Vec2f ConstantForceBehavior::getForce() {
  return force;
}

void ConstantForceBehavior::setForce(ci::Vec2f _force) {
  force = _force;
  scaledForce = force * timeStep;
}

