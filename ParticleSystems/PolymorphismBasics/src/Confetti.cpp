#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

#include "Confetti.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Confetti::Confetti(Vec2f l) : Particle(l) {

}

void Confetti::draw() { 
  float theta = lmap(location.x, 0.0f, (float)getWindowWidth(), 0.0f,(float)M_PI * 4.0f);
  color(0, 0, 0, lifespan / LIFETIME);
 
  pushMatrices();
  translate(location);
  rotate(theta);
  drawSolidRect(Rectf(- Vec2f(8, 8), Vec2f(8, 8)));
  popMatrices();
}

