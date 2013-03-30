#ifndef BALL_H
#define BALL_H

#include "cinder/app/AppBasic.h"
#include "Liquid.h"

using namespace ci;

class Ball {
private:
  float topSpeed;
  Vec2f position;
  Vec2f acceleration;
public:
  Ball(float m, Vec2f pos);
  float mass;
  Vec2f speed;

  void applyForce(Vec2f force);
  void checkEdges();

  bool isInside(Liquid * l);
  void drag(Liquid * l);

  void draw();
  void update();
};
#endif
