#ifndef BOX_H
#define BOX_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"

class Box {
private:
  ci::Rectf rect;
  float angle;
  b2World * world;

public:
  Box(b2World * world, ci::Rectf rect, bool moves);
  b2Body * body;
  void draw();
  void update();
  void killBody();
};

#endif
