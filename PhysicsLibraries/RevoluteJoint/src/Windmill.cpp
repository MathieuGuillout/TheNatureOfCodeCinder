#include <Box2D/Box2D.h>

#include "Windmill.h"
#include "Convert.h"

using namespace ci;

Windmill::Windmill(b2World * _world ,ci::Vec2f _pos) {
 
  world = _world;
  box1 = new Box(world, Rectf(_pos, _pos + Vec2f(20, 100)), false);
  box2 = new Box(world, Rectf(_pos + Vec2f(-50, 0), _pos + Vec2f(70, 5)), true);

  b2RevoluteJointDef jointDef;
  jointDef.bodyA = box1->body;
  jointDef.bodyB = box2->body;
  jointDef.localAnchorA.Set(0, -1);
  jointDef.referenceAngle = 0;
  jointDef.collideConnected = false;
  
  jointDef.motorSpeed = M_PI * 2;
  jointDef.enableMotor = true;
  jointDef.enableLimit = false;
  jointDef.maxMotorTorque = 10;


  joint = (b2RevoluteJoint*)world->CreateJoint(&jointDef);
}

void Windmill::toggleMotor() {
}

void Windmill::update() {
  box1->update();
  box2->update();
}

void Windmill::draw() {
  box1->draw();
  box2->draw();
}
