#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define RANDOM_COUNTS_LENGTH 20

class Demo : public AppBasic {
private:
  Particle * p;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
};

void Demo::prepareSettings(Settings *settings) 
{
  settings->setWindowSize( 840, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  gl::enableAlphaBlending();
  p = new Particle(getWindowCenter());
}


void Demo::update() 
{
  p->update();
  if (p->isDead()) {
    console() << "PARTICLE DEAD" << std::endl;
  }
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
  p->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
