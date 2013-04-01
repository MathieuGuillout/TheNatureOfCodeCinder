#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

#include "Particle.h"

#define LIFETIME 255

using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Particle::Particle(Vec2f l) {
  location = l;
  acceleration = Vec2f(0, 0.05);
  velocity = Vec2f(0, 0);

  lifespan = LIFETIME;
}

void Particle::update() {
  velocity += acceleration;
  location += velocity;

  lifespan -= 2.0;
}

void Particle::draw() { 
  color(0, 0, 0, lifespan / LIFETIME);
  drawSolidCircle(location, 8);
}

bool Particle::isDead() {
  return lifespan < 0.0;
}
