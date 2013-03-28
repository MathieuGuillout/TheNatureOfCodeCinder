#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Demo : public AppBasic {

  Walker * walker;
  public:
	void setup();
  void prepareSettings( Settings *settings );
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 800, 600 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  gl::clear( Color(0.1f, 0.1f, 0.1f) );
  walker = new Walker();
}

void Demo::mouseDown( MouseEvent event )
{
}

void Demo::update()
{
  walker->step();
}

void Demo::draw()
{
  walker->display();
}


CINDER_APP_BASIC( Demo, RendererGl )
