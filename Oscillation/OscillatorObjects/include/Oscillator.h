#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "cinder/app/AppBasic.h"
using namespace ci;

class Oscillator 
{
public:
  Vec2f angle;
  Vec2f amplitude;
  Vec2f velocity;

  Oscillator();
  void oscillate();
  void draw();
};
#endif
