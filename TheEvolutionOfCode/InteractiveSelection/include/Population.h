#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <string>
#include "DNA.h"
#include "Face.h"

class Population {
private:
  float mutationRate;
  std::vector<Face *> matingPool;

public:
  std::vector<Face *> elements;

  Population(float mutationRate, int nbElts);

  void fitness();
  void selection();
  void reproduction();

  void draw();
  float getMaxFitness();
  void rollover(ci::Vec2f position);
};

#endif
