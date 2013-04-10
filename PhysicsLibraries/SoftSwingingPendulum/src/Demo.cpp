#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "VerletPhysics.h"
#include "Particle.h"
#include "Chain.h"
#include "GravityBehavior.h"


using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 100

class Demo : public AppBasic 
{
private:
  VerletPhysics * physics;
  Particle * p1;
  Particle * p2;
  Chain * chain;

  bool mousePressed;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void mouseUp(MouseEvent e);
};


void Demo::prepareSettings(Settings *settings) 
{
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  mousePressed = false;

  physics = new VerletPhysics();
  physics->addBehavior(new GravityBehavior(Vec2f(0, 0.1)));
  physics->setWorldBounds(Rectf(0, 0, getWindowWidth(), getWindowHeight()));

  chain = new Chain(physics, 180, 20, 16, 0.2);
}

void Demo::mouseDown(MouseEvent e) {
  if (!mousePressed) {
    mousePressed = true;
    chain->contains(getMousePos());
  }
}

void Demo::mouseUp(MouseEvent e) {
  if (mousePressed) {
    mousePressed = false;
    chain->release();
  }
}

void Demo::update() 
{
  physics->update();
  chain->updateTail(getMousePos());
}


void Demo::draw()
{
  gl::enableAlphaBlending();
  gl::clear(Color(1, 1, 1));

  chain->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
