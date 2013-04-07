#ifndef SPRING_H
#define SPRING_H

#include <Box2D/Box2D.h>
#include "cinder/app/AppBasic.h"
#include "Box.h"

class Spring {
private:
  b2MouseJoint * mouseJoint;  
  b2World * world;
  b2Body * groundBody;
public:
  Spring(b2World * world);
  void update(ci::Vec2f pos);
  void draw();
  void bind(ci::Vec2f pos, Box * box);
  void destroy();
};

#endif
