#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

#include "Population.h"
#include "Button.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
private:
  Population * population;
  Button * button;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
};


void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 500, 600 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  Rand::randomize();
  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();

  population = new Population(0.05f, 10);
  button = new Button(Rectf(15, 150, 160, 20), string("evolve new generation"));

}

void Demo::mouseDown(MouseEvent e) {
  if (button->clicked(getMousePos())) {
    population->selection();
    population->reproduction();
  }
}

void Demo::update() {
  //population->fitness();
}

void Demo::draw() {
  gl::clear( Color(1, 1, 1) );
  population->draw();
  button->draw();
}

CINDER_APP_BASIC( Demo, RendererGl )
