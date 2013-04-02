#include "cinder/gl/gl.h"

#include "Box.h"
#include "Convert.h"

using namespace ci;
Box::Box(b2World * _world, Rectf _rect) {
  rect = _rect;
  angle = 0;
  world = _world;
  

  b2BodyDef bd;
  bd.type = b2_dynamicBody;
 
  b2Vec2 p = Convert::toPhysics(rect.getCenter());
  bd.position.Set(p.x, p.y);
  body = world->CreateBody(&bd);

  b2PolygonShape ps;
  ps.SetAsBox(Convert::toPhysics(rect.getWidth() / 2), Convert::toPhysics(rect.getHeight() / 2));

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &ps;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.3f;
  fixtureDef.restitution = 0.5f;
  body->CreateFixture(&fixtureDef);
}


void Box::update() {
  Vec2f position = Convert::toScreen(body->GetPosition());
  position -= rect.getSize() / 2;
  rect = Rectf(position, position + rect.getSize());
  angle = body->GetAngle();
}

void Box::draw() {
  gl::color( Color(1, 1, 1) );

  gl::pushMatrices();

  gl::translate(rect.getUpperLeft());
  gl::rotate(angle);

  gl::drawSolidRect(rect - rect.getUpperLeft());

  gl::popMatrices();
}

void Box::killBody() {
  world->DestroyBody(body);
}
