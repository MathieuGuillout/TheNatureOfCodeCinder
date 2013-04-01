#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

#include "Particle.h"
#include "Confetti.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

ParticleSystem::ParticleSystem(Vec2f location) {
  origin = location;
}

void ParticleSystem::addParticle() {
  float r = randFloat();
  if (r > 0.5) {
    particles.push_back(new Confetti(origin));
  } else {
    particles.push_back(new Particle(origin));
  }
}

void ParticleSystem::update() {
  vector<Particle *>::iterator itr = particles.begin();
  while(itr != particles.end()) {
    Particle * p = (Particle *)*itr;
    p->update();
    if (p->isDead()) {
      particles.erase(itr);
    }
    itr++;
  }
}

void ParticleSystem::draw() {
  vector<Particle *>::iterator itr;
  for (itr = particles.begin(); itr != particles.end(); ++itr) {
    ((Particle *)*itr)->draw();
  }
}

void ParticleSystem::applyForce(Vec2f force) {
  vector<Particle *>::iterator itr;
  for (itr = particles.begin(); itr != particles.end(); ++itr) {
    ((Particle *)*itr)->applyForce(force);
  }
}
