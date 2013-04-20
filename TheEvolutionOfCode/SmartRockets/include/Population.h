#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <string>
#include "DNA.h"
#include "Rocket.h"

class Population {
private:
  float mutationRate;
  std::vector<Rocket *> matingPool;
  int generations

public:
  std::vector<Rocket *> elements;

  Population(int nbElts, int nbGenes, float mutationRate);

  void fitness();
  void selection();
  void reproduction();
};

#endif
