#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>
#include "cinder/Vector.h"

class DNA {
public:
  std::vector<ci::Vec2f> genes;
  float maxForce;

  DNA(int nbGenes, float maxForce);
  DNA(std::vector<ci::Vec2f> genes, float maxForce);

  DNA * crossover(DNA * partner);
  void mutate(float mutationRate);
};

#endif
