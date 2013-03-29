#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Demo : public AppBasic 
{
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  Surface surface;
  gl::Texture texture;
  Perlin * perlin;
};

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 640, 480 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup()
{
  gl::enableAlphaBlending();
  gl::clear( Color(0.0, 0.0f, 0.0f) );
  
  perlin = new Perlin::Perlin();
  Area area(0, 0, getWindowWidth(), getWindowHeight());
  Surface surface(getWindowWidth(), getWindowHeight(), true);
  Surface::Iter iter = surface.getIter( area );

  float xoff = 0.0;
  while( iter.line() ) {
    float yoff = 0.0;
    while ( iter.pixel() ) {
      float bright = lmap(perlin->noise(xoff, yoff), 0.0f, 1.0f, 0.0f, 255.0f);
      iter.g() = bright;
      iter.r() = bright;
      iter.b() = bright;
      iter.a() = 10;
      yoff += 0.02;
    }
    xoff += 0.02;
  }
  texture =  gl::Texture( surface );
}


void Demo::draw()
{
  gl::draw(texture, getWindowBounds());
}


CINDER_APP_BASIC( Demo, RendererGl )
