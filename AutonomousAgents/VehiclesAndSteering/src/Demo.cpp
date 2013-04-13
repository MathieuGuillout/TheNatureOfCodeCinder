#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Vehicle.h"
#include "Target.h"

using namespace ci;
using namespace ci::app;
using namespace std;



class Demo : public AppBasic {
private:
  Vehicle * vehicle;
  Target * target;
  bool mousePressed;
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

  mousePressed = false;
  vehicle = new Vehicle(randVec2f() * 200);
  target = new Target(getWindowCenter(), 16);
}

void Demo::update() {
  vehicle->seek(target->position);
  vehicle->update();
  if (mousePressed) {
    target->position = getMousePos();
  }
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  vehicle->draw();
  target->draw();
}


void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
