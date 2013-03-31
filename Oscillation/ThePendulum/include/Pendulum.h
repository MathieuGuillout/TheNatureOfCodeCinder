#ifndef PENDULUM_H
#define PENDULUM_H

#include "cinder/app/AppBasic.h"
using namespace ci;
using namespace ci::app;

class Pendulum
{
private:
  float r;
  float angle;
  float aVelocity;
  float aAcceleration;
  float damping;
  Vec2f origin;

public:
  Pendulum(Vec2f origin, float armLength);
  void draw();
  void update();
};
#endif
