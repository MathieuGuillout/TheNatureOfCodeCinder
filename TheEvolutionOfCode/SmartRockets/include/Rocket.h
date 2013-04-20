#ifndef ROCKET_H
#define ROCKET_H

#include "cinder/cinder.h"
#include "DNA.h"

class Rocket {
private:
  ci::Vec2f location;
  ci::Vec2f velocity;
  ci::Vec2f acceleration;

  DNA * dna;
  float fitness;
  int geneCounter;
public:
  Rocket(int nbVectors);
  void applyForce(ci::Vec2f force);
  void update();
  void run();
};

#endif
