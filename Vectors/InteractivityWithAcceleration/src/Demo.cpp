#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 20

class Demo : public AppBasic 
{
private:
  Ball * balls[NB_BALLS];
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
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i] = new Ball();
  }
}

void Demo::update() {
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i]->update(getMousePos());
  }
}

void Demo::draw()
{
  gl::clear( Color(0.0, 0.0f, 0.0f) );
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i]->draw();
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
