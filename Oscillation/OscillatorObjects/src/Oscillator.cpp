#include "Oscillator.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;

Oscillator::Oscillator() 
{
  Rand::randomize();

  angle = Vec2f(0, 0);
  velocity = Vec2f(randFloat(-0.1, 0.1), randFloat(-0.1, 0.1));
  amplitude = Vec2f(randFloat(getWindowWidth() / 2), randFloat(getWindowHeight() / 2));
}

void Oscillator::oscillate() 
{
  angle += velocity;
}

void Oscillator::draw()
{
  float x = sin(angle.x) * amplitude.x;
  float y = sin(angle.y) * amplitude.y;
  pushMatrices();
  translate(getWindowCenter());

  color(Color(0, 0, 0));
  drawLine(Vec2f(0, 0), Vec2f(x, y));
  drawSolidCircle(Vec2f(x, y), 15);

  popMatrices();
}
