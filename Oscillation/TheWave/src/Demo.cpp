#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define RANDOM_COUNTS_LENGTH 20

class Demo : public AppBasic {
private:
  float startAngle;
  float angleVel;
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
  startAngle = 0;
  angleVel = 0.05;
}

void Demo::update() 
{
  startAngle += angleVel;
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
 
  float angle = startAngle;
  for( int x = 0; x < getWindowWidth() ; x += 30 ) {
    float y = lmap( sin(angle), -1.0f, 1.0f, 0.1f * getWindowHeight(), 0.9f * getWindowHeight() );
    gl::color( Color(0, 0, 0) );
    gl::drawSolidCircle(Vec2f(x, y), 16);

    angle += 8 * angleVel;
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
