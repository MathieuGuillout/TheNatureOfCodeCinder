#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;

Mover::Mover() {
  position     = Vec2f(randFloat(0, getWindowWidth()), randFloat(0, getWindowHeight() ));
  speed        = Vec2f(0, 0);
  topSpeed     = 11.0f;
}

void Mover::draw() {

  float angle = atan2(speed.y , speed.x);
  gl::color(0, 0, 0, 1);
  gl::pushMatrices();
  gl::translate(position);
  gl::rotate(angle);
  gl::drawSolidRect(Rectf(Vec2f(-15, -15), Vec2f(15, 15)));
  gl::popMatrices();
}

void Mover::checkEdges() {
  if ((position.x > getWindowWidth()) || (position.x < 0)) {
    speed.x *= -1;
  } 
  if ((position.y > getWindowHeight()) || (position.y < 0)) {
    speed.y *= -1;
  }
}

void Mover::update(Vec2f target) {
  Vec2d dir   = target - position;
  dir.normalize();
  dir *= 0.5;
  acceleration = dir;

  speed    += acceleration;
  speed.limit(topSpeed);
  
  position += speed;
 
  checkEdges();
}
