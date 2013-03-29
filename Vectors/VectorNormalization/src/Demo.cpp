#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic 
{
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  gl::enableAlphaBlending();
}

void Demo::update() {
}

void Demo::draw()
{
  gl::clear( Color(1.0f, 1.0f, 1.0f) );
  
  gl::color(0, 0, 0, 0.8);
  Vec2f mousePos = getMousePos();
  Vec2f center = Vec2f( getWindowWidth() / 2, getWindowHeight() / 2);

  gl::drawLine(center, center + (mousePos - center).normalized() * 50);
}



CINDER_APP_BASIC( Demo, RendererGl )
