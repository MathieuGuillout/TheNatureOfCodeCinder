#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Flock.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {
private:
  bool mousePressed;
  Flock * flock;
  Boid * boid;
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
  flock = new Flock();

  for (int i = 0; i < 100; i++) {
    Vec2f p = Vec2f(randFloat() * getWindowWidth(),
                    randFloat() * getWindowHeight());
    Boid * b  = new Boid(p);
    flock->addBoid(b);
  }
}

void Demo::update() {
  flock->run();
}

void Demo::draw() {
  gl::clear(Color(1, 1, 1));
  flock->draw();
}


void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
