#ifndef MOVER_H;
#define MOVER_H

#include "cinder/app/AppBasic.h"
using namespace ci;

class Mover {
private:
  Vec2f position;
  Vec2f speed;
  Vec2f acceleration;
  float topSpeed;
  void checkEdges();
public:
  Mover();
  void draw();
  void update(Vec2f target);
};
#endif
