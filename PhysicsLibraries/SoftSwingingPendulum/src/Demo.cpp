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
  
  void mouseDrag(MouseEvent e);
  void mouseDown(MouseEvent e);
  void mouseUp(MouseEvent e);

  Vec2i mousePos;
};


void Demo::prepareSettings(Settings *settings) 
{
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  mousePressed = false;

  mousePos.set(0, 0);

  physics = new VerletPhysics();
  physics->addBehavior(new GravityBehavior(Vec2f(0, 0.1)));
  physics->setWorldBounds(Rectf(0, 0, getWindowWidth(), getWindowHeight()));

  chain = new Chain(physics, 180, 20, 16, 0.2);
}

void Demo::mouseDrag(MouseEvent e)
{
	mousePos.set(e.getPos());
	chain->contains(mousePos);
}

void Demo::mouseDown(MouseEvent e)
{
	//chain->contains(e.getPos());
}

void Demo::mouseUp(MouseEvent e) {
    chain->release();
}

void Demo::update() 
{
  physics->update();
  chain->updateTail(mousePos);
}


void Demo::draw()
{
  gl::enableAlphaBlending();
  gl::clear(Color(1, 1, 1));

  chain->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
