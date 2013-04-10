#include "GravityBehavior.h"

GravityBehavior::GravityBehavior(ci::Vec2f _force) : ConstantForceBehavior(_force) {
};

GravityBehavior::GravityBehavior(ci::Vec2f _force, float _timeStep) : ConstantForceBehavior(_force) {
  configure(_timeStep);
};

void GravityBehavior::setForce(ci::Vec2f _force) {
  force = _force;
  scaledForce = force * timeStep * timeStep;
}
