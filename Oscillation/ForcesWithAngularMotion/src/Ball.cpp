#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Ball.h"


using namespace ci;
using namespace ci::app;

Ball::Ball(float m, Vec2f pos) 
{
  mass          = m;
  position      = pos;
  speed         = Vec2f(0.0f, 0.0f);
  acceleration  = Vec2f(0.0f, 0.0f);
  topSpeed      = 10.0f;
  angle         = 0.0f;
  aVelocity     = 0.0f;
  aAcceleration = 0.01f;
}

void Ball::applyForce(Vec2f force) 
{
  Vec2f f = force / mass;
  acceleration += f;
}

void Ball::draw() 
{
  gl::color(1, 0, 0, 1);

  gl::pushMatrices();
  gl::translate(position);
  gl::rotate(angle);
  gl::drawSolidRect( Rectf(-Vec2f(mass * 5, mass * 5), Vec2f(mass * 5,  mass * 5) ));
  gl::popMatrices();
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

  aAcceleration = acceleration.x ;
  aVelocity += aAcceleration;
  aVelocity = constrain(aVelocity, -20.0f, 20.0f);
  angle += aVelocity;
  
  position += speed;
 
  acceleration = Vec2f(0, 0);
  
}
