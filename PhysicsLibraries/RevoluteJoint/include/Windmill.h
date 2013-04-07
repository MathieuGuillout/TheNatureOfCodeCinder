#ifndef WINDMILL_H
#define WINDMILL_H

#include <Box2D/Box2D.h>
#include "Box.h"

class Windmill {
private:
  b2World * world;
  b2RevoluteJoint * joint;
  Box * box1;
  Box * box2;
public:
  Windmill(b2World * _world, ci::Vec2f position);
  void toggleMotor();
  void draw();
  void update();
};

#endif
