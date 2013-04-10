#include "VerletPhysics.h"
#include "GravityBehavior.h"

using namespace ci::app;

VerletPhysics::VerletPhysics() {
  numIterations = 50.0f; 
  timeStep = 1.0f; 
  setDrag(0.0f);
}

VerletPhysics::VerletPhysics(ci::Vec2f gravity, int _numIterations, float _drag, float _timeStep) {
  numIterations = _numIterations;
  timeStep = _timeStep;

  setDrag(drag);
  if (gravity.x != 0 || gravity.y != 0) {
    addBehavior(new GravityBehavior(gravity));
  }
}

void VerletPhysics::setDrag(float _drag) {
  drag = 1.0f - _drag;
}

void VerletPhysics::update() {
  updateParticles();
  updateSprings();
  applyConstraints();
}

void VerletPhysics::updateParticles() {
  for (std::list<ParticleBehavior *>::iterator b = behaviors.begin(); b != behaviors.end(); b++) {
    for (std::list<VerletParticle *>::iterator p = particles.begin(); p != particles.end(); p++) {
      ((ParticleBehavior *)*b)->apply(((VerletParticle *)*p));
    }
  }

  for (std::list<VerletParticle *>::iterator p = particles.begin(); p != particles.end(); p++) {
    ((VerletParticle *)*p)->update();
  }
}

void VerletPhysics::updateSprings() {

}

void VerletPhysics::applyConstraints() {

}

void VerletPhysics::setWorldBounds(ci::Rectf _rect) {
  bounds = _rect;
}

void VerletPhysics::addBehavior(ParticleBehavior * behavior) {
  behavior->configure(this->timeStep);
  behaviors.push_back(behavior);
}

void VerletPhysics::addParticle(VerletParticle * particle) {
  particles.push_back(particle);
}

void VerletPhysics::addSpring(VerletSpring * spring) {
  springs.push_back(spring);
}
