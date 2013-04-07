#ifndef BALL_H
#define BALL_H

#include "cinder/app/AppBasic.h"
#include <Box2D/Box2D.h>

using namespace ci;

class Ball {
private:
  b2World * world;
public:
  Ball(b2World * world, float m, Vec2f pos);
  float mass;
  Vec2f position;
  b2Body * body;

  void applyForce(b2Vec2 force);

  void draw();
  void update();
};
#endif
