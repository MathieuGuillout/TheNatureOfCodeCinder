#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "VerletPhysics.h"
#include "AttractionBehavior.h"
#include "Particle.h"


using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 100

class Demo : public AppBasic {
private:
  VerletPhysics * physics;
  Particle * attractor;
  list<Particle *> particles;

  bool mousePressed;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseUp(MouseEvent e);
  void mouseDown(MouseEvent e);
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  mousePressed = false;

  Rand::randomize();
  physics = new VerletPhysics();
  physics->setDrag(0.05f);

  for(int i = 0; i < 50; i++) {
    Particle * p = new Particle(Vec2f(randFloat() * getWindowWidth(), randFloat() * getWindowHeight()), 8);
    particles.push_back(p);
    physics->addParticle(p);
    physics->addBehavior(new AttractionBehavior(p, 32, -1));
  }
  attractor = new Particle(getWindowCenter(), 24);
  physics->addParticle(attractor);
  physics->addBehavior(new AttractionBehavior(attractor, getWindowWidth(), 0.1));
}


void Demo::update()  {
  physics->update();

  if (mousePressed) {
    attractor->lock();
    attractor->setPosition(getMousePos());
  } else {
    attractor->unlock();
  }
}


void Demo::draw() {
  gl::enableAlphaBlending();
  gl::clear(Color(1, 1, 1));

  for(list<Particle *>::iterator it = particles.begin(); it != particles.end(); it++) {
    ((Particle *)*it)->draw();
  }
  attractor->draw();
}

void Demo::mouseDown(MouseEvent e) {
  mousePressed = true;
}

void Demo::mouseUp(MouseEvent e) {
  mousePressed = false;
}

CINDER_APP_BASIC( Demo, RendererGl )
