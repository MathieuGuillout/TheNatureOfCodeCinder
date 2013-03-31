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
  float r;
  float theta;
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 500, 500 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  r = 50;
  theta = 0;
  gl::clear( Color(1, 1, 1) );
}


void Demo::update()
{
  theta += 0.02;
  r = 50 + theta;
}

void Demo::draw()
{

  float x = r * cos( theta );
  float y = r * sin( theta );

  gl::color( Color( 0, 0, 0 ) );
  gl::drawSolidCircle( getWindowCenter() + Vec2f(x, y), 1 );
  
}


CINDER_APP_BASIC( Demo, RendererGl )
