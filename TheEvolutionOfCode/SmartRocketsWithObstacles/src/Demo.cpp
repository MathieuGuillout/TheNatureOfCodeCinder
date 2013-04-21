#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

#include "Population.h"
#include "Target.h"
#include "Obstacle.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
private:
  Population * population;
  Target * target;
  vector<Obstacle *> obstacles;
  int lifetime;
  int lifeCounter;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 500, 600 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  Rand::randomize();
  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();

  lifetime = 500;
  lifeCounter = 500;

  target = new Target(Vec2f(100, 100), 30);
  population = new Population(100, lifetime, 0.01, target->position);

  obstacles.push_back(new Obstacle(Rectf(-100, 300, 200, 310)));
  obstacles.push_back(new Obstacle(Rectf(100, 200, 400, 210)));
}

void Demo::update() {
  if (lifeCounter < lifetime) {
    population->live(obstacles);
    lifeCounter++;
  } else {
    gl::clear( Color(1, 1, 1) );
    lifeCounter = 0;
    population->fitness();
    population->selection();
    population->reproduction();
  }
}

void Demo::draw() {
  for(int i = 0; i < (int)population->elements.size(); i++) {
    population->elements.at(i)->draw();
  }
  for(int i = 0; i < (int)obstacles.size(); i++) {
    obstacles.at(i)->draw();
  }
  target->draw();
}

CINDER_APP_BASIC( Demo, RendererGl )
