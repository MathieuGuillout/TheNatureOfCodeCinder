#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Particle.h"


using namespace ci;
using namespace ci::app;

Particle::Particle(Vec2f pos) : VerletParticle(pos)
{
  radius = 4;
}

void Particle::draw() 
{
  gl::color(0.8, 0.8, 0.8, 1);
  gl::drawSolidCircle( position, radius );
  gl::color(0, 0, 0, 1);
  gl::drawStrokedCircle( position, radius );
}
