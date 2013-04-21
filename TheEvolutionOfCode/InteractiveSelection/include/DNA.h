#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>
#include "cinder/Vector.h"

class DNA {
public:
  std::vector<float> genes;
  int len;

  DNA();
  DNA(std::vector<float> genes);

  DNA * crossover(DNA * partner);
  void mutate(float mutationRate);
};

#endif
