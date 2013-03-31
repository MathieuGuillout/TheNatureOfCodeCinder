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
  void update();
  void draw();
  float angle;
  float aVelocity;
  float aAcceleration;
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 200, 200 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  angle = 0;
  aVelocity = 0;
  aAcceleration = 0.005;
}


void Demo::update()
{
  aVelocity += aAcceleration;
  angle += aVelocity;
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );

  gl::pushMatrices();
  gl::translate(getWindowCenter());
  gl::rotate(angle);

  gl::color( Color(0, 0, 0) );
  gl::drawLine(Vec2f(-50, 0),Vec2f(50, 0));
  gl::drawSolidCircle(Vec2f(50, 0), 8);
  gl::drawSolidCircle(Vec2f(-50, 0), 8);

  gl::popMatrices();
  
}


CINDER_APP_BASIC( Demo, RendererGl )
