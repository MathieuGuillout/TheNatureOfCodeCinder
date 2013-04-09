#include "cinder/app/AppBasic.h"
#include "Attractor.h"
#include "Convert.h"


using namespace ci;
using namespace ci::app;

Attractor::Attractor(b2World * _world) {
  world = _world;
  position = Vec2f(getWindowWidth() / 2, getWindowHeight() / 2);
  mass = 40.0f;
  G = 0.02;

  b2BodyDef bd;
  bd.type = b2_staticBody;
  bd.position = Convert::toPhysics(position);

  b2CircleShape cs;
  cs.m_radius = Convert::toPhysics(mass);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &cs;

  body = world->CreateBody(&bd);
  body->CreateFixture(&fixtureDef);

}

void Attractor::draw() {
  gl::color(0.2, 0.2, 0.2, 1);
  position = Convert::toScreen(body->GetPosition());
  gl::drawSolidCircle(position, mass);
}

b2Vec2 Attractor::attract(Ball * ball) {
  b2Vec2 force = body->GetPosition();
  force -= ball->body->GetPosition();
  float distance = constrain(force.Length(), 5.0f, 25.0f);
  force.Normalize();
  float strength = ( G * mass * mass ) / ( distance * distance );
  force *= strength;
  return force;
}
