#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>

class DNA {
public:
  std::vector<float> genes;
  float fitness;
  DNA(int nbGenes);
  DNA(std::vector<float> _genes);
  
  void computeFitness(std::string target);
  void mutate(float mutationRate);
  DNA * crossover(DNA * partner);
  DNA * copy();
};

#endif
