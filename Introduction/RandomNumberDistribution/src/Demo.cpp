#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define RANDOM_COUNTS_LENGTH 20

class Demo : public AppBasic {
private:
  int randomCounts[RANDOM_COUNTS_LENGTH];
public:
  void setup();
  void prepareSettings( Settings *settings );
  void mouseDown( MouseEvent event ); 
  void update();
  void draw();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 240 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  for(int i = 0; i < RANDOM_COUNTS_LENGTH; i++) {
    randomCounts[i] = 0;
  }
}

void Demo::mouseDown( MouseEvent event )
{
}

void Demo::update()
{
  randomCounts[rand() % RANDOM_COUNTS_LENGTH]++;
}

void Demo::draw()
{
  gl::clear( Color(0.1f, 0.1f, 0.1f) );
  int w = getWindowWidth() / RANDOM_COUNTS_LENGTH;
  for (int x = 0; x < RANDOM_COUNTS_LENGTH ; x++ ) {
    gl::drawSolidRect(Rectf(x*w, 
                            getWindowHeight(),
                            ((x+1) * w) - 1, 
                            getWindowHeight() - randomCounts[x]));
  }
}


CINDER_APP_BASIC( Demo, RendererGl )
