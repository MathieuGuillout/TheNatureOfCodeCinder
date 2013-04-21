#include "DNA.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

DNA::DNA(int nbGenes, float _maxForce) {
  maxForce = _maxForce;
  for (int i = 0; i < nbGenes; i++) {
    genes.push_back(randVec2f() * randFloat(maxForce));
  }
}

DNA::DNA(vector<Vec2f> _genes, float _maxForce) {
  genes = _genes;
  maxForce = _maxForce;
}

DNA * DNA::crossover(DNA * partner) {

  vector<Vec2f> child;

  int crossover = randInt((int)genes.size());
  for (int i = 0; i < (int)genes.size(); i++) {
    if (i > crossover) {
      child.push_back(genes.at(i));
    } else {
      child.push_back(partner->genes.at(i)); 
    }
  }

  return new DNA(child, maxForce);

}

void DNA::mutate(float mutationRate) {
  
  for (int i = 0; i < (int)genes.size(); i++) {
    if (randFloat(1) < mutationRate) {
      float angle = randFloat(M_PI * 2);
      genes.at(i) = Vec2f(cos(angle), sin(angle)) * randFloat(maxForce);
    }
  }
}
