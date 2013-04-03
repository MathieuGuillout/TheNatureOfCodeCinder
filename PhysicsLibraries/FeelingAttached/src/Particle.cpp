#include "cinder/gl/gl.h"

#include "Particle.h"
#include "Convert.h"

using namespace ci;
Particle::Particle(b2World * _world, Vec2f _position, float _radius) {
  position = _position;
  radius = _radius;
  world = _world;
  
  b2BodyDef bd;
  bd.type = b2_dynamicBody;
 
  b2Vec2 p = Convert::toPhysics(position);
  bd.position.Set(p.x, p.y);
  body = world->CreateBody(&bd);

  b2CircleShape circle;
  circle.m_p.Set(0.0f, 0.0f);
  circle.m_radius = Convert::toPhysics(radius);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &circle;
  body->CreateFixture(&fixtureDef);
}


void Particle::update() {
  position = Convert::toScreen(body->GetPosition());
}

void Particle::draw() {
  gl::color( Color(0, 0, 0) );
  gl::drawSolidCircle(position, radius);
}

void Particle::killBody() {
  world->DestroyBody(body);
}
