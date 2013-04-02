#ifndef BOUNDARY_H
#define BOUNDARY_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"

class Boundary {
private:
  ci::Vec2f position;
  ci::Vec2f size;
  b2Body * body;
  b2World * world;
public:
  Boundary(b2World * world, ci::Vec2f _position, ci::Vec2f _size); 
  void draw();
};

#endif
