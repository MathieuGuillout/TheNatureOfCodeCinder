#ifndef ROCKET_H
#define ROCKET_H

#include <vector>
#include "cinder/cinder.h"
#include "DNA.h"
#include "Obstacle.h"

class Rocket {
private:
  ci::Vec2f location;
  ci::Vec2f velocity;
  ci::Vec2f acceleration;

  int geneCounter;
  ci::Vec2f target;
  bool stopped;
  int finishTime;
  float recordDist;

public:
  float fitness;
  bool hitTarget;
  DNA * dna;

  Rocket(int nbVectors, ci::Vec2f target, DNA * dna);
  void applyForce(ci::Vec2f force);
  void update();
  void run();
  void draw();
  void computeFitness();
  void checkTarget();
  void checkObstacles(std::vector<Obstacle *> obstacles);
};

#endif
