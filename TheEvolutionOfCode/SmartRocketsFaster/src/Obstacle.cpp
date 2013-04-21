#include "Obstacle.h"
#include "cinder/gl/gl.h"

using namespace ci;

Obstacle::Obstacle(Rectf r) {
  rect = r;
}

bool Obstacle::contains(Vec2f point) {
  return rect.contains(point);
}

void Obstacle::draw() {
  gl::color(Color(0, 0, 0));
  gl::drawSolidRect(rect);
}
