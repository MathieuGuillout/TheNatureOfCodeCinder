#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 10

class Demo : public AppBasic 
{
private:
  Ball * balls[NB_BALLS];
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
    balls[i] = new Ball(
      randFloat(0.1, 2), 
      Vec2f(randFloat(0, getWindowWidth()), randFloat(0, getWindowHeight()))
    );
  }
}

void Demo::update() 
{
  // Friction coefficient
  float c = 0.05;
  for (int i = 0; i < NB_BALLS; i++) {
    for (int j = 0; j < NB_BALLS; j++) {
      if (j != i) {
        balls[i]->applyForce(balls[j]->attract(balls[i]));
      }
    }
    balls[i]->update();
  }
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
  for (int i = 0; i < NB_BALLS; i++) {
    balls[i]->draw();
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
