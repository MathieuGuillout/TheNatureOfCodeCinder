#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <vector>
#include <Box2D/Box2D.h>

#include "Convert.h"
#include "MyContactListener.h"
#include "Box.h"

using namespace ci;
using namespace ci::app;
using namespace std;


b2Vec2 gravity(0.0f, 10.0f);
b2World world(gravity);

class Demo : public AppBasic {
private:
  list<Box *> boxes;
  Box * boundary;
public:
  void setup();
  void prepareSettings(Settings *settings);
  void draw();
  void update();
  void mouseDown(MouseEvent event); 
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize(640, 480);
  settings->setFrameRate(60.0f);
}

void Demo::mouseDown(MouseEvent event) {
  Box * box = new Box(&world, Rectf(getMousePos() - Vec2f(8, 8), getMousePos() + Vec2f(8, 8)), true, Color(1, 0, 0));
  boxes.push_back(box);
}

void Demo::setup() {
  MyContactListener * cl = new MyContactListener();
  world.SetContactListener(cl);
  boundary = new Box(&world, Rectf(0, getWindowHeight() - 30, getWindowWidth(), getWindowHeight()), false, Color(0, 0, 0));
}

void Demo::update() {
  world.Step(0.01f, 6, 2); 
  for (list<Box *>::iterator b = boxes.begin(); b != boxes.end(); ++b) {
    ((Box *)*b)->update();
  }
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  for (list<Box *>::iterator b = boxes.begin(); b != boxes.end(); ++b) {
    ((Box *)*b)->draw();
  }
  boundary->draw();
}


CINDER_APP_BASIC(Demo, RendererGl)
