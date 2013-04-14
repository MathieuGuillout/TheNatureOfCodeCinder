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
  vector<Vehicle *> vehicles;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void mouseUp(MouseEvent e);
  void addVehicle();
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 840, 280 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  Rand::randomize();
  gl::enableAlphaBlending();

  path = new Path();
  int nbPoints = 10;
  for(int i = 0; i <= nbPoints; i++) {
    path->addPoint(Vec2f(i * getWindowWidth() / nbPoints, randFloat(getWindowHeight())));
  }

  addVehicle();
  mousePressed = false;
}

void Demo::addVehicle() {
  Vehicle * vehicle = new Vehicle(path->points.at(0) + 10 * randVec2f());
  vehicle->velocity = Vec2f(1 + randFloat(), randFloat());
  vehicles.push_back(vehicle);
}

void Demo::update() {
  for(int i = 0; i < (int)vehicles.size(); i++) {
    vehicles.at(i)->follow(path);
    vehicles.at(i)->update();
  }
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  path->draw();
  for(int i = 0; i < (int)vehicles.size(); i++) {
    vehicles.at(i)->draw();
  }
}


void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;

  addVehicle();
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
