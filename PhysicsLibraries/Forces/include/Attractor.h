#ifndef ATTRACTOR_H
#define ATTRACTOR_H

#include "cinder/app/AppBasic.h"
#include <Box2D/Box2D.h>
#include "Ball.h"

using namespace ci;

class Attractor{
private:
  float G;
  b2World * world;
public:
  float mass;
  Vec2f position;
  b2Body * body;

  Attractor(b2World * world);
  void draw();
  b2Vec2 attract(Ball * ball);
};
#endif
