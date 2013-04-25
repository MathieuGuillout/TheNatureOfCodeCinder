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
  gl::drawString(text, rect.getUpperLeft() + Vec2f(5, 5),ColorA(0,0,0,1), Font("Arial", 15));
}

bool Button::clicked(Vec2f pos) {
  return rect.contains(pos);
}
