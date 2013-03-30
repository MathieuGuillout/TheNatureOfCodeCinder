#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Ball.h"
#include "Liquid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 10

class Demo : public AppBasic 
{
private:
  Ball * balls[NB_BALLS];
  Liquid * liquid;
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
    balls[i] = new Ball(randFloat(1, 2), Vec2f(randFloat(0, getWindowWidth()), 50));
  }
  liquid = new Liquid(0, getWindowHeight() * 2.0/3, getWindowWidth(), getWindowHeight() * 1.0/3, 0.1);
}

void Demo::update() 
{
  // Friction coefficient
  float c = 0.05;
  Vec2f gravity = Vec2f(0.0f, 0.01f); 
  for (int i = 0; i < NB_BALLS; i++) {
    
    if (balls[i]->isInside(liquid)) {
      balls[i]->drag(liquid);
    }

    balls[i]->applyForce(gravity * 10 * balls[i]->mass);
    balls[i]->update();
    balls[i]->checkEdges();
  }
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i]->draw();
  }
  liquid->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
