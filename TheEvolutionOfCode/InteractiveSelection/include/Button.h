#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "cinder/Rect.h"

class Button {
private:
  ci::Rectf rect;
  std::string text;
public:
  Button(ci::Rectf rect, std::string s);
  void draw();
  bool clicked(ci::Vec2f position);
};

#endif
