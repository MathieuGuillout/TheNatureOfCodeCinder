#include "cinder/Rand.h"
#include "Pair.h"
#include "Convert.h"

using namespace ci;

Pair::Pair(b2World * world, Vec2f pos, float radius) {

  float len = 32;

  p1 = new Particle(world, pos, radius);
  p2 = new Particle(world, pos + Vec2f(randFloat(), randFloat()), radius);

  b2DistanceJointDef jointDef;
  jointDef.Initialize(p1->body, p2->body, Convert::toPhysics(p1->position), Convert::toPhysics(p2->position));
  jointDef.frequencyHz = 0;
  jointDef.dampingRatio = 0;
  jointDef.length = Convert::toPhysics(len);

  world->CreateJoint(&jointDef);
}

void Pair::draw() {
  gl::color( Color(0, 0, 0) );
  gl::drawLine(p1->position, p2->position);
  p1->draw();
  p2->draw();
}

void Pair::update() {
  p1->update();
  p2->update();
}
