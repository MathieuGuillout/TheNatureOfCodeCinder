#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>
#include <stack>
#include <string>

#include "Population.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic {
private:
  Population * population;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void branch(float len);
};


void Demo::mouseDown(MouseEvent e) {
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 500, 600 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();
  
  string target = string("to be or not to be");
  population = new Population(600, target.length(), 0.003);
  population->setTarget(target);
}

void Demo::update() {
  population->reproduction();
}

void Demo::draw() {
  gl::color( Color(1, 1, 1) );
  console() << population->bestMatch() << endl;
}

CINDER_APP_BASIC( Demo, RendererGl )
