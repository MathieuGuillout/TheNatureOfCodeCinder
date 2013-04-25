#include "Food.h"
#include "cinder/gl/gl.h"

using namespace ci;

Food::Food(Vec2f loc) {
  location = loc;
}

void Food::draw() {
  gl::color(Color(1, 0, 0));
  gl::drawSolidRect(Rectf(location - Vec2f(-5, -5), location + Vec2f(5, 5)));
}
