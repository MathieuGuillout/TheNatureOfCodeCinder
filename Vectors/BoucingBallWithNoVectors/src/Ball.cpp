#include "cinder/app/AppBasic.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;

Ball::Ball() {
  x = 100; 
  y = 100;
  xspeed = 6;
  yspeed = 5.3;
}

void Ball::draw() {
  gl::color(1, 1, 1, 0.8);
  gl::drawSolidCircle( Vec2f(x, y), 20.0f );
}

void Ball::update() {
  x = x + xspeed;
  y = y + yspeed;

  if ((x > getWindowWidth()) || (x < 0)) {
    xspeed = xspeed * -1;
  } 
  if ((y > getWindowHeight()) || (y < 0)) {
    yspeed = yspeed * -1;
  }
}
