#include "cinder/app/AppBasic.h"
#include "Attractor.h"


using namespace ci;
using namespace ci::app;

Attractor::Attractor() {
  position = Vec2f(getWindowWidth() / 2, getWindowHeight() / 2);
  mass = 20.0f;
  G = 0.2;
}

void Attractor::draw() {
  gl::color(0.2, 0.2, 0.2, 1);
  gl::drawSolidCircle( position, mass * 2.0f );
  gl::color(0, 0, 0, 1);
  gl::drawStrokedCircle( position, mass * 2.0f );
}

Vec2f Attractor::attract(Ball * ball) {
  Vec2f force = position - ball->position;
  float distance = constrain(force.length(), 5.0f, 25.0f);
  force.safeNormalize();
  float strength = ( G * mass * mass ) / ( distance * distance );
  force = force * strength;
  return force;
}
