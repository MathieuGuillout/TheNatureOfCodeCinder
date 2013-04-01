#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

#include "Particle.h"


using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Particle::Particle(Vec2f l, gl::Texture text) {
  location = l;
  acceleration = Vec2f(0, 0);
  float vx = randGaussian() * 0.3;
  float vy = randGaussian() * 0.3 - 1.0;
  velocity = Vec2f(vx, vy);
  myTexture = text; 
  mass = 1;
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
  color(1, 1, 1, lifespan / LIFETIME);
  gl::enableAdditiveBlending();
  gl::draw(myTexture, Rectf(location - Vec2f(20, 20), location + Vec2f(20, 20)));
}

bool Particle::isDead() {
  return lifespan < 0.0;
}
