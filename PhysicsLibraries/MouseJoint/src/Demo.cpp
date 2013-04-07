#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <list>
#include <Box2D/Box2D.h>

#include "Box.h"
#include "Boundary.h"
#include "Spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;


b2Vec2 gravity(0.0f, 10.0f);
b2World world(gravity);

class Demo : public AppBasic {
private:
  Box * box;
  Spring * spring;
  list<Boundary> boundaries;
  bool mousePressed;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
  void mouseDown(MouseEvent event); 
  void mouseUp(MouseEvent event); 
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  box = new Box(&world, Rectf(getWindowCenter(), getWindowCenter() + Vec2f(16, 16)));
  spring = new Spring(&world);

  boundaries.push_back(Boundary(&world, Rectf( 0,   0,   640, 10 ))); 
  boundaries.push_back(Boundary(&world, Rectf( 0,   470, 640, 480 ))); 
  boundaries.push_back(Boundary(&world, Rectf( 0,   0,   10,  480 ))); 
  boundaries.push_back(Boundary(&world, Rectf( 630, 0,   640, 480 ))); 

  mousePressed = false;
}

void Demo::mouseDown(MouseEvent event) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent event) {
  mousePressed = false;
  spring->destroy();
}

void Demo::update() {
  if (mousePressed && box->rect.contains(getMousePos())) {
    spring->bind(getMousePos(), box);
  }
  
  world.Step(0.01f, 1, 1); 
  box->update();
  spring->update(getMousePos());
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  for(list<Boundary>::iterator b = boundaries.begin(); b != boundaries.end(); b++) {
    b->draw();
  }
  box->draw();
  spring->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
