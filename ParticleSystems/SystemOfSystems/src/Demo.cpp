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
  vector<ParticleSystem *> systems;
public:
  void setup();
  void prepareSettings(Settings *settings);
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
}

void Demo::mouseDown(MouseEvent event) {
  systems.push_back(new ParticleSystem(getMousePos()));
}

void Demo::update() {
  vector<ParticleSystem *>::iterator itr = systems.begin();
  while (itr != systems.end()) {
    (*itr)->addParticle();
    (*itr)->update();
    itr++;
  }
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  vector<ParticleSystem *>::iterator itr = systems.begin();
  while (itr != systems.end()) {
    (*itr)->draw();
    itr++;
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
