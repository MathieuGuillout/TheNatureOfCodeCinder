#include "cinder/app/AppBasic.h"
#include "Ball.h"


using namespace ci;
using namespace ci::app;

Ball::Ball() {
  position     = Vec2f(getWindowWidth() / 2, getWindowHeight() / 2);
  speed        = Vec2f(0, 0);
  acceleration = Vec2f(-0.001, 0.01);
  topSpeed     = 10.0f;
}

void Ball::draw() {
  gl::color(1, 1, 1, 0.8);
  gl::drawSolidCircle( position, 20.0f );
}

void Ball::checkEdges() {
  if ((position.x > getWindowWidth()) || (position.x < 0)) {
    speed.x *= -1;
  } 
  if ((position.y > getWindowHeight()) || (position.y < 0)) {
    speed.y *= -1;
  }
}

void Ball::update() {
  speed    += acceleration;
  speed.limit(topSpeed);
  
  position += speed;
 
  checkEdges();
}
