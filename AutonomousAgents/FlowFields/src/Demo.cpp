#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Vehicle.h"
#include "FlowField.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {
private:
  vector<Vehicle *> vehicles;
  FlowField * flowField;
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
  for(int i = 0; i < 50; i++) {
    vehicles.push_back(new Vehicle(Vec2f(randFloat(getWindowWidth()), randFloat(getWindowHeight()))));
  }
  flowField = new FlowField(getWindowSize());
}

void Demo::update() {
  for(int i = 0; i < (int)vehicles.size(); i++) {
    vehicles.at(i)->follow(flowField);
    vehicles.at(i)->update();
  }
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  for(int i = 0; i < (int)vehicles.size(); i++) {
    vehicles.at(i)->draw();
  }
  flowField->draw();
}


void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
