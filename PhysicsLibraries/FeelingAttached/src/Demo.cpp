#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <list>
#include <Box2D/Box2D.h>

#include "CurvyBoundary.h"
#include "Pair.h"
#include "Convert.h"

using namespace ci;
using namespace ci::app;
using namespace std;


b2Vec2 gravity(0.0f, 10.0f);
b2World world(gravity);

class Demo : public AppBasic {
private:
  list<Pair> pairs;
  CurvyBoundary * curvyBoundary;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
  void mouseDown(MouseEvent event); 
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 840, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  gl::enableAlphaBlending();
  curvyBoundary = new CurvyBoundary(&world);
}

void Demo::mouseDown(MouseEvent event) {
  Pair pair = Pair(&world, getMousePos(), 8);
  pairs.push_back(pair);
}

void Demo::update() {
  world.Step(0.01f, 1, 1); 
  for (list<Pair>::iterator b = pairs.begin(); b != pairs.end(); ++b) {
    b->update();
  }
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  for (list<Pair>::iterator b = pairs.begin(); b != pairs.end(); ++b) {
    b->draw();
  }
  curvyBoundary->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
