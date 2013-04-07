#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include <Box2D/Box2D.h>
#include "Ball.h"
#include "Convert.h"


using namespace ci;
using namespace ci::app;

Ball::Ball(b2World * _world, float m, Vec2f pos) {
  world        = _world;
  mass         = m;
  position     = pos;

  b2BodyDef bd;
  bd.type = b2_dynamicBody;
  bd.position = Convert::toPhysics(position);

  b2CircleShape cs;
  cs.m_radius = Convert::toPhysics(mass);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &cs;

  body = world->CreateBody(&bd);
  body->CreateFixture(&fixtureDef);

}

void Ball::applyForce(b2Vec2 force) {
  body->ApplyForce(force, body->GetWorldCenter());
}

void Ball::draw() {
  position = Convert::toScreen(body->GetPosition());
  gl::color(1, 0, 0, 0.7);
  gl::drawSolidCircle( position, mass);
  gl::color(1, 0, 0, 1);
  gl::drawStrokedCircle( position, mass);
}

