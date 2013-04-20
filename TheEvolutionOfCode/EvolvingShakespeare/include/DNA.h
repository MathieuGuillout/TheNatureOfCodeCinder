#ifndef DNA_H
#define DNA_H

#include <string>
#include <vector>

class DNA {
private:
  std::vector<char> genes;
public:
  float fitness;
  DNA(int nbGenes);
  void computeFitness(std::string target);
  DNA * crossover(DNA * partner);
  void mutate(float mutationRate);
  std::string getPhrase();
};

#endif
