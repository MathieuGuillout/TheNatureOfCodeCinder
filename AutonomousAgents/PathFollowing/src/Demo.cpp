#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Vehicle.h"
#include "Path.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {
private:
  bool mousePressed;
  Path * path;
  Vehicle * vehicle;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void mouseUp(MouseEvent e);
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  Rand::randomize();
  gl::enableAlphaBlending();

  path = new Path();
  vehicle = new Vehicle(Vec2f(40, 40));
  mousePressed = false;
}

void Demo::update() {
  vehicle->follow(path);
  vehicle->update();
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  path->draw();
  vehicle->draw();
}


void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
