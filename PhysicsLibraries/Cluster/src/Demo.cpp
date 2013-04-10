#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "VerletPhysics.h"
#include "Cluster.h"


using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 100

class Demo : public AppBasic 
{
private:
  VerletPhysics * physics;
  Cluster * cluster;

  bool mousePressed;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
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
  cluster = new Cluster(physics, 33, 200, getWindowCenter());
}


void Demo::update() 
{
  physics->update();
}


void Demo::draw()
{
  gl::enableAlphaBlending();
  gl::clear(Color(1, 1, 1));

  cluster->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
