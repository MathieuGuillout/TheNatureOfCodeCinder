#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;

Mover::Mover( Vec2f _position ) {
  position     = _position;
  speed        = Vec2f(0, 0);
  topSpeed     = 11.0f;
  mass         = 16.0f;
  damping      = 0.98f;
  radius       = mass;
}

void Mover::draw() {

  float angle = atan2(speed.y , speed.x);
  gl::color(0, 0, 0, 1);
  gl::drawSolidCircle(Vec2f(position), radius);
}

void Mover::checkEdges() {
  if ((position.x > getWindowWidth()) || (position.x < 0)) {
    speed.x *= -1;
  } 
  if ((position.y > getWindowHeight()) || (position.y < 0)) {
    speed.y *= -1;
  }
}

void Mover::applyForce(Vec2f force) 
{
  Vec2f f = force / mass;
  acceleration += f;
}

void Mover::update() 
{
  speed    += acceleration;
  speed    *= damping;
  speed.limit(topSpeed);
  
  position += speed;
 
  checkEdges();
  acceleration = Vec2f(0, 0);
}

void Mover::drag( Vec2f pos , Vec2f dragOffset ) 
{
  position = pos ;
}
