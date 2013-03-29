#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic 
{
private:
  Ball * ball;
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
  ball = new Ball();
}

void Demo::update() {
  ball->update();
}

void Demo::draw()
{
  gl::clear( Color(0.0, 0.0f, 0.0f) );
  ball->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
