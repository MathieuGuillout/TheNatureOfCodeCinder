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
  vector<Vehicle *> vehicles;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void mouseUp(MouseEvent e);
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 400, 400 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  Rand::randomize();
  gl::enableAlphaBlending();

  mousePressed = false;
  for (int i = 0; i < 50; i++) {
    vehicles.push_back(new Vehicle(Vec2f(randFloat(getWindowWidth()), randFloat(getWindowHeight()))));
  }
}

void Demo::update() {
  for (int i = 0; i < (int)vehicles.size(); i++) {
    vehicles.at(i)->separate(vehicles);
    vehicles.at(i)->update();
  }
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  for (int i = 0; i < (int)vehicles.size(); i++) {
    vehicles.at(i)->draw();
  }
}


void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
