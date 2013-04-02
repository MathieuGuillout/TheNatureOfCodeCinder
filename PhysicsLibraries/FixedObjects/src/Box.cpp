#include "cinder/gl/gl.h"

#include "Box.h"
#include "Convert.h"

using namespace ci;
Box::Box(b2World * _world, Vec2f _position) {
  position = _position;
  angle = 0;
  size = Vec2f(16, 16);
  world = _world;
  

  b2BodyDef bd;
  bd.type = b2_dynamicBody;
 
  b2Vec2 p = Convert::toPhysics(_position);
  bd.position.Set(p.x, p.y);
  body = world->CreateBody(&bd);

  b2PolygonShape ps;
  ps.SetAsBox(Convert::toPhysics(size.x / 2), Convert::toPhysics(size.y / 2));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &ps;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.restitution = 0.5f;
  body->CreateFixture(&fixtureDef);
}


void Box::update() {
  position = Convert::toScreen(body->GetPosition());
  angle = body->GetAngle();
}

void Box::draw() {
  gl::color( Color(1, 1, 1) );

  gl::pushMatrices();

  gl::translate(position);
  gl::rotate(angle);
  gl::drawSolidRect(Rectf(-size / 2, size / 2));

  gl::popMatrices();
}

void Box::killBody() {
  world->DestroyBody(body);
}
