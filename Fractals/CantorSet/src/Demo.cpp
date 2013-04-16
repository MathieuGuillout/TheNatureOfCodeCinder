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
  void cantor(Vec2f pos, float len);
};


void Demo::mouseDown(MouseEvent e) {
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 600, 200 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();
}

void Demo::update() {
}

void Demo::draw() {
  cantor(Vec2f(30, 20), getWindowWidth() - 60);
}

void Demo::cantor(Vec2f pos, float len) {
  gl::color( Color(0, 0, 0) );
  if (len >= 1) {
    gl::drawSolidRect(Rectf(pos, pos + Vec2f(len, 10)));
    cantor(pos + Vec2f(0, 20), len / 3);
    cantor(pos + Vec2f(len * 2.0/3, 20), len / 3);
  }
}

CINDER_APP_BASIC( Demo, RendererGl )
