#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Ball.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 100

class Demo : public AppBasic 
{
private:
  Ball * balls[NB_BALLS];
  Attractor * attractor;
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
  gl::enableAlphaBlending();
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i] = new Ball(randFloat(0.5, 3), Vec2f(randFloat(0, getWindowWidth()), 50));
  }
  attractor = new Attractor();
}

void Demo::update() 
{
  // Friction coefficient
  float c = 0.05;
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i]->applyForce(attractor->attract(balls[i]));
    balls[i]->update();
  }
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i]->draw();
  }
  attractor->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
