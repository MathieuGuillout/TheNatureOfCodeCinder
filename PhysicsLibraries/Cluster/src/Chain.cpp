#include "Chain.h"
#include "VerletSpring.h"
#include "cinder/gl/gl.h"

using namespace ci::app;

Chain::Chain(VerletPhysics * physics, float l, int n, float r, float s) {

  offset = ci::Vec2f(0, 0);
  dragged = false;

  totalLength = l;
  numPoints = n;
  radius = r;
  strength = s;

  float len = totalLength / numPoints;

  for(int i = 0; i < numPoints; ++i) {
    Particle * particle = new Particle(ci::Vec2f(ci::app::getWindowWidth() / 2, 50 + i * len));

    physics->addParticle(particle);
    particles.push_back(particle);

    if (i != 0) {
      Particle * previous = particles.at(i - 1);
      VerletSpring * spring = new VerletSpring(particle, previous, len, strength);
      physics->addSpring(spring);
    }
  }

  Particle * head = particles.at(0);
  head->lock();

  tail = particles.at(numPoints - 1);
  tail->radius = radius;
}

void Chain::contains(ci::Vec2f pos) {
  float d = (tail->position - pos).length();
  if (d < radius) {
    offset = tail->position - pos;
    tail->lock();
    dragged = true;
  }
}

void Chain::release() {
  tail->unlock();
  dragged = false;
}

void Chain::updateTail(ci::Vec2f pos) {
  if (dragged) {
    tail->position = pos + offset;
  }
}

void Chain::draw() {
  gl::color(0, 0, 0, 1);
  for (int i = 0; i < numPoints - 1; ++i) {
    gl::drawLine(particles.at(i)->position, particles.at(i+1)->position);
  }
  tail->draw(); 
}
