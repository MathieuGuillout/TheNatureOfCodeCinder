#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "Population.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Population::Population(int nbElts, int nbGenes, float _mutationRate) {
  mutationRate = _mutationRate;
  for (int i = 0; i < nbElts; i++) {
    elements.push_back(new Rocket(nbGenes));
  }
}


vector<DNA *> Population::matingPool() {

  vector<DNA *> matingPool;


  return matingPool;
}

void Population::fitness() {
  for (int i = 0; i < (int)elements.size(); i++) {
    elements.at(i)->computeFitness(target);
  }
}

void Population::selection() {

  matingPool.clear();

  for (int i = 0; i < (int)elements.size(); i++) {
    
    int n = (int)(elements.at(i)->fitness * 100);
    for (int j = 0; j < n; j++) {
      matingPool.push_back(elements.at(i));
    }
  }

}

void Population::reproduction() {


  for (int i = 0; i < (int)elements.size(); i++) {
    DNA * partnerA = pool.at(randInt(pool.size()));
    DNA * partnerB = pool.at(randInt(pool.size()));
    
    DNA * child = partnerA->crossover(partnerB);
    child->mutate(mutationRate);

    elements.at(i) = child;
  }

}

void Population::live() {

  for (int i = 0; i < (int)elements.size(); i++) {
    elements.at(i)->run();
  }
}
