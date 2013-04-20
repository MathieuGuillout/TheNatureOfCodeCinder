#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <string>
#include "DNA.h"

class Population {
private:
  std::vector<DNA *> elements;
  float mutationRate;
  std::string target;

public:
  Population(int nbElts, int nbGenes, float mutationRate);

  std::vector<DNA *> matingPool();
  void setTarget(std::string target);
  void reproduction();
  std::string bestMatch();
};

#endif
