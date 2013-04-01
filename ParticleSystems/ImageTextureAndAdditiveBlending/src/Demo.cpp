#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
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
  gl::Texture myTexture = loadImage("resources/texture.png");
  particleSystem = new ParticleSystem(getWindowCenter(), myTexture);
}


void Demo::update() {
  Vec2f gravity = Vec2f(0, 0.01);
  particleSystem->applyForce(gravity);

  float dx = lmap((float)getMousePos().x, 0.0f, (float)getWindowWidth(), -0.2f, 0.2f);
  Vec2f wind = Vec2f(dx, 0);
  particleSystem->applyForce(wind);

  particleSystem->addParticle();
  particleSystem->update();
}

void Demo::draw() {
  gl::clear( Color(0, 0, 0) );
  particleSystem->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
