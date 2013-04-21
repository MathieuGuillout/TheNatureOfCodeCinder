#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "cinder/Vector.h"
#include "cinder/Rect.h"

class Obstacle {
public:
  ci::Rectf rect;
  Obstacle(ci::Rectf r);
  bool contains(ci::Vec2f p);
  void draw();
};


#endif
