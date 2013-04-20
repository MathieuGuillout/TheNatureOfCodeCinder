#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>
#include "cinder/Vector.h"

class DNA {
private:
  std::vector<ci::Vec2f> genes;
public:
  float fitness;
  DNA(int nbGenes, float maxForce);
  void computeFitness();
  DNA * crossover(DNA * partner);
  void mutate(float mutationRate);
};

#endif
