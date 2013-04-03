#ifndef SURFACE_H
#define SURFACE_H

#include "cinder/Vector.h"
#include <vector>
#include <Box2D/Box2D.h>

class CurvyBoundary {
private:
  std::vector<ci::Vec2f> surface;
public:
  CurvyBoundary(b2World * world);
  void draw();
};

#endif
