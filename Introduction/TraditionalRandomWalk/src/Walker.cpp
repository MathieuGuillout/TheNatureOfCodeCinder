#include "Walker.h"
#include "cinder/app/AppBasic.h"
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

void Walker::step()
{
  x += (rand() % 3) - 1;
  y += (rand() % 3) - 1;
}
