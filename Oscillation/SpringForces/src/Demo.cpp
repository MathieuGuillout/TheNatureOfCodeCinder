#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Mover.h"
#include "Spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define RANDOM_COUNTS_LENGTH 20

class Demo : public AppBasic {
private:
  Mover * mover;
  Spring * spring;
  bool mousePressed;
  bool isDragging;
public:
  void setup();
  void prepareSettings( Settings *settings );
  void mouseDown( MouseEvent event ); 
  void mouseUp( MouseEvent event ); 
  void draw();
  void update();
};

void Demo::prepareSettings(Settings *settings) 
{
  settings->setWindowSize( 840, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  spring = new Spring( Vec2f( getWindowWidth() / 2, 10 ), 150 );
  mover = new Mover( Vec2f( getWindowWidth() / 6, 200 ) );
  mousePressed = false;
  isDragging = false;
}

void Demo::mouseUp( MouseEvent event ) 
{
  mousePressed = false;
  isDragging = false;
}

void Demo::mouseDown( MouseEvent event ) 
{
  mousePressed = true;
}


void Demo::update() 
{
  if (mousePressed) {
    float d = (mover->position - getMousePos()).length();
    if (d < mover->radius * 1.5 || isDragging) {
      isDragging = true;
      mover->drag(getMousePos(), mover->position - getMousePos());
    }
  }
  Vec2f gravity = Vec2f( 0, 2 );
  mover->applyForce( gravity );

  spring->connect( mover );
  mover->update();
}

void Demo::draw()
{
  gl::clear( Color(1, 1, 1) );
  mover->draw();
  spring->draw();
  spring->drawLine( mover );
}


CINDER_APP_BASIC( Demo, RendererGl )
