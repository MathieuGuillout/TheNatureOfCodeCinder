#ifndef BOX_H
#define BOX_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"

class Box {
private:
  float angle;
  b2World * world;

public:
  Box(b2World * world, ci::Rectf rect);
  
  ci::Rectf rect;
  b2Body * body;
  
  void draw();
  void update();
  void killBody();
};

#endif
