#include "Spring.h"
#include "Convert.h"

using namespace ci;
using namespace ci::app;

Spring::Spring(b2World * _world) {
  world = _world;
  b2BodyDef bd;
  groundBody = world->CreateBody(&bd);
  mouseJoint = 0;
}

void Spring::update(Vec2f pos) {
  if (mouseJoint != 0) {
    mouseJoint->SetTarget(Convert::toPhysics(pos));
  }
}

void Spring::draw() {
  if (mouseJoint != 0) {
    Vec2f v1 = Convert::toScreen(mouseJoint->GetAnchorA());
    Vec2f v2 = Convert::toScreen(mouseJoint->GetAnchorB());

    gl::color( Color(0, 0, 0) );
    gl::drawLine(v1, v2);
  }
}

void Spring::bind(Vec2f pos, Box * box) {
  if (mouseJoint == 0) {
    b2MouseJointDef md;
    md.bodyA = groundBody;
    md.bodyB = box->body;
    
    b2Vec2 v = Convert::toPhysics(pos);
    md.target.Set(v.x, v.y);
    md.maxForce = 1000.0 * box->body->GetMass();
    md.frequencyHz = 5.0;
    md.dampingRatio = 0.9;

    mouseJoint = (b2MouseJoint *)world->CreateJoint(&md);
  }
}

void Spring::destroy() {
  if (mouseJoint != 0) {
    world->DestroyJoint(mouseJoint);
    mouseJoint = 0;
  }
}
