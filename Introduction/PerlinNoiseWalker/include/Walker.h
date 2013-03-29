#include "cinder/Perlin.h"

class Walker {
private:
  float x;
  float y;
  float tx;
  float ty;
  cinder::Perlin * perlin;
public:
  Walker();
  void display();
  void step();
};
