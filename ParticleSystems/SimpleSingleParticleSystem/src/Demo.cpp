#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include <vector>

#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
private:
  ParticleSystem * particleSystem;
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
  particleSystem = new ParticleSystem(Vec2f(getWindowWidth() / 2, 40));
}


void Demo::update() {
  particleSystem->addParticle();
  particleSystem->update();
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  particleSystem->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
