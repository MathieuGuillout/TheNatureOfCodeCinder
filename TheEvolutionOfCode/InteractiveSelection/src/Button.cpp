#include "Button.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace std;

Button::Button(Rectf r, string s) {
  rect = r;
  text = s;
}

void Button::draw() {
  gl::color(Color(0, 0, 0));
  gl::drawStrokedRect(rect);
}

bool Button::clicked(Vec2f pos) {
  return rect.contains(pos);
}
