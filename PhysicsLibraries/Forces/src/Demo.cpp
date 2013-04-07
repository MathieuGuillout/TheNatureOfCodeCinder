#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <list>
#include <Box2D/Box2D.h>

#include "Ball.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_BALLS 100

b2Vec2 gravity(0.0f, -10.0f);
b2World world(gravity);

class Demo : public AppBasic {
private:
  list<Ball> balls;
  Attractor * attractor;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  Rand::randomize();
  gl::enableAlphaBlending();
  for (int i = 0; i < NB_BALLS; i++) {
    balls.push_back(
      Ball(&world, 
           randFloat(1, 20), 
           Vec2f(randFloat(getWindowWidth()), randFloat(getWindowHeight())))
    );
  }
  attractor = new Attractor(&world);
}

void Demo::update() {
  // Friction coefficient
  float c = 0.05;
  for (list<Ball>::iterator ball = balls.begin(); ball != balls.end(); ball++) {
    ball->applyForce(attractor->attract((Ball *)&ball));
  }
  world.Step(0.01f, 6, 7); 
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  for (list<Ball>::iterator ball = balls.begin(); ball != balls.end(); ball++) {
    ball->draw();
  }
  attractor->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
