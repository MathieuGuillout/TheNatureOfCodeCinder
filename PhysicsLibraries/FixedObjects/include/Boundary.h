#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"

class Boundary {
private:
  ci::Rectf rect;
  b2Body * body;
  b2World * world;
public:
  Boundary(b2World * world, ci::Rectf rect); 
  void draw();
};

#endif
