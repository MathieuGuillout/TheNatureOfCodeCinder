#include "Boundary.h"
#include "Convert.h"

using namespace ci;

Boundary::Boundary(b2World * _world, Rectf _rect) {
  world = _world;
  rect = _rect;
  
  b2BodyDef bd;
  bd.type = b2_staticBody;
 
  b2Vec2 p = Convert::toPhysics(rect.getCenter());
  bd.position.Set(p.x, p.y);
  body = world->CreateBody(&bd);

  b2PolygonShape ps;
  ps.SetAsBox(Convert::toPhysics(rect.getWidth() / 2), Convert::toPhysics(rect.getHeight() / 2));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &ps;
  body->CreateFixture(&fixtureDef);
}

void Boundary::draw() {
  gl::color( Color(0.7, 0.3, 0.3) );
  gl::drawSolidRect(rect);
}
