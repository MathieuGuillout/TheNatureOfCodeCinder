#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"

#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

ParticleSystem::ParticleSystem(Vec2f location, gl::Texture text) {
  origin = location;
  myTexture = text;
}

void ParticleSystem::addParticle() {
  particles.push_back(new Particle(origin, myTexture));
}

void ParticleSystem::update() {
  list<Particle *>::iterator itr = particles.begin();
  while(itr != particles.end()) {
    Particle * p = (Particle *)*itr;
    if (p->isDead()) {
      particles.erase(itr);
    } else {
      p->update();
    }
    itr++;
  }
}

void ParticleSystem::draw() {
  list<Particle *>::iterator itr;
  for (itr = particles.begin(); itr != particles.end(); ++itr) {
    ((Particle *)*itr)->draw();
  }
}

void ParticleSystem::applyForce(Vec2f force) {
  list<Particle *>::iterator itr;
  for (itr = particles.begin(); itr != particles.end(); ++itr) {
    ((Particle *)*itr)->applyForce(force);
  }
}

