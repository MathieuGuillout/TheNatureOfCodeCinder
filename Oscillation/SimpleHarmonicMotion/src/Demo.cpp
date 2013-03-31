#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define RANDOM_COUNTS_LENGTH 20

class Demo : public AppBasic {
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  float period;
  float amplitude;
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 600, 200 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  period = 120;
  amplitude = 200;
}


void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );

  gl::pushMatrices();
  gl::translate(getWindowCenter());

  float x = amplitude * cos( 2 * M_PI * getElapsedFrames() / period);

  gl::color( Color(0, 0, 0) );
  gl::drawLine(Vec2f(0, 0),Vec2f(x, 0));
  gl::drawSolidCircle(Vec2f(x, 0), 8);

  gl::popMatrices();
  
}


CINDER_APP_BASIC( Demo, RendererGl )
