#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
  void setup();
  void prepareSettings( Settings *settings );
  void mouseDown( MouseEvent event ); 
  void update();
  void draw();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 360 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  gl::enableAlphaBlending();
  gl::clear( Color(0.1f, 0.1f, 0.1f) );
  Rand::randomize();
}

void Demo::mouseDown( MouseEvent event )
{
}

void Demo::update()
{
}

void Demo::draw()
{
  float num = Rand::randGaussian();
  float sd = 60; 
  float mean = getWindowWidth() / 2;

  float x = sd * num + mean;
  gl::color(1, 1, 1, 0.01);
  gl::drawSolidEllipse( Vec2f(x, getWindowHeight() / 2), 32, 16);
}


CINDER_APP_BASIC( Demo, RendererGl )
