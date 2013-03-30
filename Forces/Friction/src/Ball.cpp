#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Ball.h"


using namespace ci;
using namespace ci::app;

Ball::Ball(float m, Vec2f pos) 
{
  mass         = m;
  position     = pos;
  speed        = Vec2f(0.0f, 0.0f);
  acceleration = Vec2f(0.0f, 0.0f);
  topSpeed     = 10.0f;
}

void Ball::applyForce(Vec2f force) 
{
  Vec2f f = force / mass;
  acceleration += f;
}

void Ball::draw() 
{
  gl::color(0.5, 0.5, 0.5, 1);
  gl::drawSolidCircle( position, mass * 16.0f );
  gl::color(0, 0, 0, 0.7);
  gl::drawStrokedCircle( position, mass * 16.0f );
}

void Ball::checkEdges() 
{
  if ((position.x > getWindowWidth()) || (position.x < 0)) {
    speed.x *= -1;
    if (position.x < 0) position.x = 0;
    if (position.x > getWindowWidth()) position.x = getWindowWidth();
  } 
  if ((position.y > getWindowHeight()) || (position.y < 0)) {
    speed.y *= -1;
    if (position.y < 0) position.y = 0;
    if (position.y > getWindowHeight()) position.y = getWindowHeight();
  }
}

void Ball::update()
{
  speed    += acceleration;
  speed.limit(topSpeed);
  
  position += speed;
 
  acceleration = Vec2f(0, 0);
}
