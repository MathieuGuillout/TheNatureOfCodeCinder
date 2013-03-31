#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Pendulum.h"
using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Pendulum::Pendulum( Vec2f _origin, float _r ) 
{
  r = _r;
  origin = _origin;
  aVelocity = 0;
  aAcceleration = 0;
  angle = M_PI / 4;
  damping = 0.998;
}

void Pendulum::update() 
{
  float gravity = 0.5;
  aAcceleration = (-1 * gravity / r ) * sin(angle);
  aVelocity += aAcceleration;

  angle += aVelocity;

  aVelocity *= damping;
}

void Pendulum::draw()
{
  Vec2f location = Vec2f( r * sin( angle ), r * cos( angle ) );
  location += origin;

  color( Color( 0, 0, 0 ) );
  drawLine( origin, location );
  drawSolidCircle( location, 16 );
}
