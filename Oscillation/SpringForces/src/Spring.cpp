#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Spring.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Spring::Spring( Vec2f _anchor, float _len ) 
{
  anchor = _anchor;
  len = _len;
  k = 0.1;
}

void Spring::draw() 
{
  color( Color( 0, 0, 0 ) );
  drawSolidRect( Rectf( anchor - Vec2f(5, 5), anchor + Vec2f(5, 5) ) );
}

void Spring::drawLine( Mover * mover )
{
  color( Color( 0, 0, 0 ) );
  gl::drawLine( mover->position, anchor );
}

void Spring::connect( Mover * mover ) 
{
  Vec2f force = mover->position - anchor;
  float d = force.length();
  float stretch = d - len;

  force.safeNormalize();
  force *= -1 * k * stretch;

  mover->applyForce(force);
}
