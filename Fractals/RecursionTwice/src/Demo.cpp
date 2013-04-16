#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void drawCircle(Vec2f pos, float radius);
};


void Demo::mouseDown(MouseEvent e) {
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 400, 400 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();
}

void Demo::update() {
}

void Demo::draw() {
  drawCircle(getWindowCenter(), 200);
}

void Demo::drawCircle(Vec2f pos, float radius) {
  gl::color( Color(0, 0, 0) );
  gl::drawStrokedCircle(pos, radius);
  if (radius > 2) {
    drawCircle(pos + Vec2f(radius / 2, 0), radius / 2);
    drawCircle(pos - Vec2f(radius / 2, 0), radius / 2);
  }
}

CINDER_APP_BASIC( Demo, RendererGl )
