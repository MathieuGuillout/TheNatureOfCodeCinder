#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <list>
#include <Box2D/Box2D.h>

#include "CurvyBoundary.h"
#include "Particle.h"
#include "Convert.h"
#include "Windmill.h"

using namespace ci;
using namespace ci::app;
using namespace std;


b2Vec2 gravity(0.0f, 10.0f);
b2World world(gravity);

class Demo : public AppBasic {
private:
  list<Particle> particles;
  Box * ground;
  Windmill * windmill;
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
  
  //DebugDraw dd;
  //world->SetDebugDraw(&dd);

  windmill = new Windmill(&world, Vec2f(getWindowWidth() / 2, 285));
  ground = new Box(&world, Rectf(0, getWindowHeight() - 100, getWindowWidth(), getWindowHeight() ), false);
}

void Demo::mouseDown(MouseEvent event) {
  Particle particle = Particle(&world, getMousePos(), 8);
  particles.push_back(particle);
}

void Demo::update() {
  world.Step(0.01f, 1, 1); 
  for (list<Particle>::iterator b = particles.begin(); b != particles.end(); ++b) {
    b->update();
  }
  windmill->update();
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  for (list<Particle>::iterator b = particles.begin(); b != particles.end(); ++b) {
    b->draw();
  }
  windmill->draw();
  ground->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
