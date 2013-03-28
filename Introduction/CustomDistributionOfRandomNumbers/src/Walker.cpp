#include "Walker.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

Walker::Walker() 
{
  int width = getWindowWidth();
  int height = getWindowHeight();
  x = width / 2;
  y = height / 2;
}

void Walker::display() 
{
  gl::drawSolidCircle( Vec2f(x, y), 1.0f );
}

float Walker::montecarlo() {
  while(true) {
    float r1 = Rand::randFloat();
    float probability = r1;
    float r2 = Rand::randFloat(); 
    if (r2 < probability) {
      return r1;
    }
  }
}

void Walker::step()
{
  float stepSize = montecarlo() * 10;
  float stepx = randFloat(-stepSize, stepSize);
  float stepy = randFloat(-stepSize, stepSize);
  x += stepx;
  y += stepy;
}
