#ifndef BALL_H
#define BALL_H

#include "cinder/app/AppBasic.h"

using namespace ci;

class Ball {
private:
  float topSpeed;
  float G;
  Vec2f acceleration;
public:
  Ball(float m, Vec2f pos);
  float mass;
  Vec2f position;
  Vec2f speed;

  void applyForce(Vec2f force);
  void checkEdges();
  Vec2f attract(Ball * ball);

  void draw();
  void update();
};
#endif
