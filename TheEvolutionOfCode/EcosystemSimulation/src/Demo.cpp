#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>
#include <stack>
#include <string>

#include "World.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
private:
  World * world;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
};


void Demo::mouseDown(MouseEvent e) {
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 600, 400 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();

  world = new World(20);
}

void Demo::update() {
  world->update();
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  world->draw();
}

CINDER_APP_BASIC( Demo, RendererGl )
