#include "VerletParticle.h"

VerletParticle::VerletParticle(ci::Vec2f _pos, float _weight) {
  position = _pos;
  isLocked = false;
  force = ci::Vec2f(0, 0);

  prev = _pos;
  temp = _pos;
  setWeight(_weight);
  weight = _weight;
}

void VerletParticle::setPosition(ci::Vec2f _pos) {
  position = _pos;
}

void VerletParticle::setWeight(float _weight) {
  weight = _weight;
  invWeight = 1.0f / _weight;
}

void VerletParticle::lock()   { isLocked = true; }
void VerletParticle::unlock() { isLocked = false; }
void VerletParticle::update() {
  if (!isLocked) {
    applyBehaviors();
    applyForce();
    applyConstraints();
  }
}

void VerletParticle::applyBehaviors() {
}

void VerletParticle::applyForce() {
  temp = position;
  position += (position - prev) + force * weight;
  prev = temp;
  force = ci::Vec2f(0, 0);
}

void VerletParticle::applyConstraints() {

}

void VerletParticle::addForce(ci::Vec2f f) {
  force += f;
}

void VerletParticle::scaleVelocity(float _scl) {
  prev += (position - prev) * (1.0f - _scl);
}
