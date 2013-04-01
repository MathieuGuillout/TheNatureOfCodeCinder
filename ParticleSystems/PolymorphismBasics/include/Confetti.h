#ifndef CONFETTI_H;
#define CONFETTI_H

#include "cinder/app/AppBasic.h"
#include "Particle.h"

class Confetti : public Particle {
public:
  Confetti(ci::Vec2f l);
  void draw();
};

#endif
