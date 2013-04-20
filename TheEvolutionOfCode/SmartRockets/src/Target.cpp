#include "Target.h"

#include "cinder/gl/gl.h"

using namespace ci;

Target::Target(ci::Vec2f pos, float r) {
  position = pos;
  radius = r;
}

void Target::draw() {
  gl::color(Color(0, 0, 0));
  gl::drawSolidCircle(position, radius);
}
