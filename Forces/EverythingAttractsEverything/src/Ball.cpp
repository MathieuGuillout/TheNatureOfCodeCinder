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
  G = 0.4;
}

void Ball::applyForce(Vec2f force) 
{
  Vec2f f = force / mass;
  acceleration += f;
}

void Ball::draw() 
{
  gl::color(0, 0, 0, 0.7);
  gl::drawSolidCircle( position, mass * 16.0f );
  gl::color(0, 0, 0, 1);
  gl::drawStrokedCircle( position, mass * 16.0f );
}


Vec2f Ball::attract(Ball * ball) {
  Vec2f force = position - ball->position;
  float distance = constrain(force.length(), 5.0f, 25.0f);
  force.safeNormalize();
  float strength = ( G * mass * mass ) / ( distance * distance );
  force = force * strength;
  return force;
}


void Ball::update()
{
  speed    += acceleration;
  speed.limit(topSpeed);
  
  position += speed;
 
  acceleration = Vec2f(0, 0);
}
