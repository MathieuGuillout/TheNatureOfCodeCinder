#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <vector>
#include <Box2D/Box2D.h>

#include "Convert.h"
#include "Box.h"
#include "Boundary.h"

using namespace ci;
using namespace ci::app;
using namespace std;


b2Vec2 gravity(0.0f, 10.0f);
b2World world(gravity);

class Demo : public AppBasic {
private:
  list<Box> boxes;
  list<Boundary> boundaries;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
  void mouseDown(MouseEvent event); 
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  boundaries.push_back(Boundary(&world, Rectf(Vec2f(100, 100), Vec2f(200, 110))));
  boundaries.push_back(Boundary(&world, Rectf(Vec2f(150, 250), Vec2f(450, 260))));
  boundaries.push_back(Boundary(&world, Rectf(Vec2f(400, 400), Vec2f(600, 410))));
}

void Demo::mouseDown(MouseEvent event) {
  Box box = Box(&world, Rectf(getMousePos(), getMousePos() + Vec2f(16, 16)));
  boxes.push_back(box);
}

void Demo::update() {
  world.Step(0.01f, 1, 1); 
  for (list<Box>::iterator b = boxes.begin(); b != boxes.end(); ++b) {
    b->update();
  }
}

void Demo::draw() {
  gl::clear( Color(0, 0, 0) );
  for (list<Box>::iterator b = boxes.begin(); b != boxes.end(); ++b) {
    b->draw();
  }
  for (list<Boundary>::iterator b = boundaries.begin(); b != boundaries.end(); ++b) {
    b->draw();
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
