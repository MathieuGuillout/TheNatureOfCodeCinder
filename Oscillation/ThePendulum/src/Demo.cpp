#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Pendulum.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define RANDOM_COUNTS_LENGTH 20

class Demo : public AppBasic {
private:
  Pendulum * pendulum;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void draw();
  void update();
  float period;
  float amplitude;
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 840, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  pendulum = new Pendulum(Vec2f(getWindowWidth() / 2, 0), 275);
}

void Demo::update() 
{
  pendulum->update();
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
  pendulum->draw();
}


CINDER_APP_BASIC( Demo, RendererGl )
