#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Liquid.h"


using namespace ci;
using namespace ci::app;

Liquid::Liquid(float x_, float y_, float w_, float h_, float c_) {
  x = x_;
  y = y_;
  w = w_;
  h = h_;
  c = c_;
}

void Liquid::draw() {
  gl::color(0, 0, 1, 0.1);
  gl::drawSolidRect(Rectf(x, y, x + w, y + h));
}
