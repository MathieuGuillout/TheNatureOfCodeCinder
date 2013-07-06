#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "VerletPhysics.h"
#include "Particle.h"
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

  bool mousePressed;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDrag(MouseEvent e);
  void mouseUp(MouseEvent e);
  void mouseDown(MouseEvent e);

  Vec2i mMousePos;
};

// Mouse events
void Demo::mouseUp(MouseEvent e)
{
	mousePressed = false; 

}

void Demo::mouseDown(MouseEvent e)
{
	mousePressed = true;
	mMousePos = e.getPos();
}

void Demo::mouseDrag(MouseEvent e)
{
	mMousePos = e.getPos();
		
}

void Demo::prepareSettings(Settings *settings) 
{
  settings->setWindowSize( 400, 400 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  mousePressed = false;

  physics = new VerletPhysics();
  physics->addBehavior(new GravityBehavior(Vec2f(0, 0.5)));
  physics->setWorldBounds(Rectf(0, 0, getWindowWidth(), getWindowHeight()));
 
  p1 = new Particle(Vec2f(190, 120));
  p2 = new Particle(Vec2f(190, 300));
  p1->lock();

  VerletSpring * spring = new VerletSpring(p1, p2, 180, 0.01);
  physics->addParticle(p1);
  physics->addParticle(p2);
  physics->addSpring(spring);
}

void Demo::update() 
{
  physics->update();
  if (mousePressed) {
    p2->lock();
	p2->position = mMousePos;
    p2->unlock();
  }
}


void Demo::draw()
{
  gl::enableAlphaBlending();
  gl::clear(Color(1, 1, 1));

  gl::color(Color(0, 0, 0));
  gl::drawLine(p1->position, p2->position);
  p1->draw();
  p2->draw();

}


CINDER_APP_BASIC( Demo, RendererGl )
