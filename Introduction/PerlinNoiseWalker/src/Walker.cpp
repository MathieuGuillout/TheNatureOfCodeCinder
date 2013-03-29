#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"
#include "cinder/gl/gl.h"

#include "Walker.h"

using namespace ci;
using namespace ci::app;

Walker::Walker() 
{
  x = 0;
  y = 0; 
  tx = 101;
  ty = 1000;
  perlin = new Perlin::Perlin();
}

void Walker::display() 
{
  gl::color(1, 1, 1, 0.1);
  gl::drawSolidCircle( Vec2f(x, y), 10.0f );
}


void Walker::step()
{
  float w = getWindowWidth(); float h = getWindowHeight();
  x = (w/2) + lmap(perlin->noise(tx), 0.0f, 1.0f, 0.0f, 0.5f * w);
  y = (h/2) + lmap(perlin->noise(ty), 0.0f, 1.0f, 0.0f, 0.5f * h);
  
  tx += 0.01;
  ty += 0.01;
}
