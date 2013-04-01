#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
private:
  vector<Particle *> particles;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 840, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {
  gl::enableAlphaBlending();
}


void Demo::update() {

  particles.push_back(new Particle(Vec2f(getWindowWidth()/2, 50)));

  vector<Particle *>::iterator itr = particles.begin();
  while(itr != particles.end()) {
    Particle * p = (Particle *)*itr;
    p->update();
    if (p->isDead()) {
      particles.erase(itr);
    }
    itr++;
  }

}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );

  vector<Particle *>::iterator itr;
  for (itr = particles.begin(); itr != particles.end(); ++itr) {
    ((Particle *)*itr)->draw();
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
