#ifndef POPULATION_H
#define POPULATION_H

#include "cinder/Vector.h"
#include <vector>
#include <string>
#include "DNA.h"
#include "Rocket.h"

class Population {
private:
  float mutationRate;
  std::vector<Rocket *> matingPool;
  int generations;
  int nbGenes;
  ci::Vec2f target;

public:
  std::vector<Rocket *> elements;

  Population(int nbElts, int nbGenes, float mutationRate, ci::Vec2f target);

  void fitness();
  void selection();
  void reproduction();

  void live();
  float getMaxFitness();
};

#endif
