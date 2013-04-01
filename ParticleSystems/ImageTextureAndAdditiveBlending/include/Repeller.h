#ifndef REPELLER_H 
#define REPELLER_H

#include "Particle.h"

class Repeller { 
public:
  ci::Vec2f location;
  float radius;
  
  Repeller(ci::Vec2f l);
  void draw();
  ci::Vec2f repel(Particle * p);
};

#endif
