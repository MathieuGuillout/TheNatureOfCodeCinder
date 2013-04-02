#include "Boundary.h"
#include "Convert.h"

using namespace ci;

Boundary::Boundary(b2World * _world, Vec2f _position, Vec2f _size) {
  world = _world;
  size = _size;
  position = _position;
  
  b2BodyDef bd;
  bd.type = b2_staticBody;
 
  b2Vec2 p = Convert::toPhysics(_position);
  bd.position.Set(p.x, p.y);
  body = world->CreateBody(&bd);

  b2PolygonShape ps;
  ps.SetAsBox(Convert::toPhysics(size.x / 2), Convert::toPhysics(size.y / 2));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &ps;
  body->CreateFixture(&fixtureDef);
}

void Boundary::draw() {
  position = Convert::toScreen(body->GetPosition());
  
  gl::color( Color(1, 1, 1) );
  gl::drawSolidRect(Rectf(position, position + size ));
}
