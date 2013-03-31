#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include "cinder/app/AppBasic.h"
#include "Ball.h"

using namespace ci;

class Attractor{
private:
  float G;
public:
  float mass;
  Vec2f position;

  Attractor();
  void draw();
  Vec2f attract(Ball * ball);
};
#endif
