#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

#include "Particle.h"


using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Particle::Particle(Vec2f l) {
  location = l;
  acceleration = Vec2f(0, 0);
  velocity = Vec2f(randFloat(-1.0f, 1.0f), randFloat(-2.0f, 0.0f));
  
  mass = 10;
  lifespan = LIFETIME;
}

void Particle::update() {
  velocity += acceleration;
  location += velocity;
  
  acceleration *= 0;
  lifespan -= 2.0;
}

void Particle::applyForce(Vec2f force) {
  Vec2f f = force;
  f = f / mass;
  acceleration += f;
}

void Particle::draw() { 
  color(0, 0, 0, lifespan / LIFETIME);
  drawSolidCircle(location, 8);
}

bool Particle::isDead() {
  return lifespan < 0.0;
}
