#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "CA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {
private:
  CA * ca;
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

void Demo::setup() {
  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();
  ca = new CA(getWindowSize(), 1);
}

void Demo::update() {
  ca->generate();
}

void Demo::draw() {
  ca->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
