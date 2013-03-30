#ifndef LIQUID_H
#define LIQUID_H

#include "cinder/app/AppBasic.h"
using namespace ci;

class Liquid {
public:
  Liquid(float x_, float y_, float w_, float h_, float c_);
  float x, y, w, h;
  float c;
  void draw();
};

#endif
