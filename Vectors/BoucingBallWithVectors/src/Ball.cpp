#include "cinder/app/AppBasic.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;

Ball::Ball() {
  position = Vec2f(100, 100);
  speed    = Vec2f(6, 5.3);
}

void Ball::draw() {
  gl::color(1, 1, 1, 0.8);
  gl::drawSolidCircle( position, 20.0f );
}

void Ball::update() {
  position += speed;

  if ((position.x > getWindowWidth()) || (position.x < 0)) {
    speed.x *= -1;
  } 
  if ((position.y > getWindowHeight()) || (position.y < 0)) {
    speed.y *= -1;
  }
}
