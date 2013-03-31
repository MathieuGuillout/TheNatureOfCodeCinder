#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Oscillator.h"
using namespace ci;
using namespace ci::app;
using namespace std;

#define NB_OBJECTS 20

class Demo : public AppBasic {
public:
  Oscillator * oscillators[NB_OBJECTS];
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 600, 600 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  for (int i = 0; i < NB_OBJECTS; i++) {
    oscillators[i] = new Oscillator();
  }
}

void Demo::update()
{
  for (int i = 0; i < NB_OBJECTS; i++) {
    oscillators[i]->oscillate();
  }
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );

  for (int i = 0; i < NB_OBJECTS; i++) {
    oscillators[i]->draw();
  }
  
}


CINDER_APP_BASIC( Demo, RendererGl )
