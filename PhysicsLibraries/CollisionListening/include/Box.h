#ifndef BOX_H
#define BOX_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"

class Box {
private:
  ci::Rectf rect;
  ci::Color color;
  float angle;
  b2Body * body;
  b2World * world;

public:
  Box(b2World * world, ci::Rectf _rect, bool isMoving, ci::Color _color);
  void draw();
  void update();
  void change();
  void killBody();
};

#endif
