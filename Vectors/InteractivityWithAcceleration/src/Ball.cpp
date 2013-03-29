#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Ball.h"


using namespace ci;
using namespace ci::app;

Ball::Ball() {
  position     = Vec2f(randFloat(0, getWindowWidth()), randFloat(0, getWindowHeight() ));
  speed        = Vec2f(0, 0);
  topSpeed     = 10.0f;
}

void Ball::draw() {
  gl::color(1, 1, 1, 0.7);
  gl::drawSolidCircle( position, 10.0f );
}

void Ball::checkEdges() {
  if ((position.x > getWindowWidth()) || (position.x < 0)) {
    speed.x *= -1;
  } 
  if ((position.y > getWindowHeight()) || (position.y < 0)) {
    speed.y *= -1;
  }
}

void Ball::update(Vec2f target) {
  Vec2d dir   = target - position;
  dir.normalize();
  dir *= 0.5;
  acceleration = dir;

  speed    += acceleration;
  speed.limit(topSpeed);
  
  position += speed;
 
  checkEdges();
}
