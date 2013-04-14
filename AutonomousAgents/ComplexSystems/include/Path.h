#ifndef PATH_H
#define PATH_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Shape2d.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Path {

public:
  Vec2f start, end;
  Shape2d shape;
  float radius;

  Path() {
    Vec2f size = getWindowSize();
    radius = 5;
    start = Vec2f(0, size.y / 3);
    end =   Vec2f(size.x, size.y * 2.0 / 3);

    shape = Shape2d();
    
    shape.moveTo( start + Vec2f(0,  radius) );
    shape.lineTo( end   + Vec2f(0,  radius) );
    shape.lineTo( end   + Vec2f(0, -radius) );
    shape.lineTo( start + Vec2f(0, -radius) );

    shape.close();

  }

  void draw() {
    gl::color(Color(0.4, 0.4, 0.4));
    gl::drawSolid(shape);
  }
};

#endif
