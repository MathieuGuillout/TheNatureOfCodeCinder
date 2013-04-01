#ifndef CONFETTI_H
#define CONFETTI_H

#include "Particle.h"

class Confetti : public Particle {
public:
  Confetti(ci::Vec2f l);
  void draw();
};

#endif
