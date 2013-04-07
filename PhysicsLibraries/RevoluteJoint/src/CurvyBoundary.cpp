#include "cinder/app/AppBasic.h"
#include "CurvyBoundary.h"
#include "Convert.h"

using namespace ci;
using namespace ci::app;

CurvyBoundary::CurvyBoundary(b2World * world) {

  float avg = getWindowHeight() * 0.76;
  surface.push_back(Vec2f(0, getWindowHeight()));
  for(int i = 0; i < getWindowWidth(); i += 1) {
    surface.push_back(Vec2f(i, avg + sin(i * 0.03) * (avg / 5) ));
  }
  surface.push_back(Vec2f(getWindowWidth(), getWindowHeight()));
  
  b2ChainShape chain;
  b2Vec2 vertices[surface.size()]; 
  for (int i = 0; i < (int)surface.size(); i++) {
    vertices[i] = Convert::toPhysics(surface.at(i));
  }
  chain.CreateChain(vertices, surface.size());

  b2BodyDef bd;
  b2Body * body = world->CreateBody(&bd);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &chain;
  body->CreateFixture(&fixtureDef);
}

void CurvyBoundary::draw() {
  gl::color( 0, 0, 0, 0.70 );
  
  gl::drawSolid(PolyLine2f(surface));
}
