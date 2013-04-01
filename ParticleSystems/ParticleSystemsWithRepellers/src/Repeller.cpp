#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

#include "Repeller.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Repeller::Repeller(Vec2f l) {
  location = l;
  radius = 30;
}

void Repeller::draw() { 
  color(1, 0, 0);
  drawSolidCircle(location, radius);
}

Vec2f Repeller::repel(Particle * p) {
  Vec2f dir = location - p->location;
  float d = constrain((float)dir.length(), 5.0f, 100.0f);
  dir.safeNormalize();
  
  float G = 1200;
  float force = -1.0f * G / ( d * d );
  
  return dir * force;
}
