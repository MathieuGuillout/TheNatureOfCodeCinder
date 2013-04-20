#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "Population.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Population::Population(int nbElts, int nbGenes, float _mutationRate) {
  mutationRate = _mutationRate;
  for (int i = 0; i < nbElts; i++) {
    elements.push_back(new DNA(nbGenes));
  }
}

void Population::setTarget(string s) {
  target = s;
}

vector<DNA *> Population::matingPool() {

  vector<DNA *> matingPool;

  for (int i = 0; i < (int)elements.size(); i++) {
    
    int n = (int)(elements.at(i)->fitness * 100);
    for (int j = 0; j < n; j++) {
      matingPool.push_back(elements.at(i));
    }
  }

  return matingPool;
}

void Population::reproduction() {

  for (int i = 0; i < (int)elements.size(); i++) {
    elements.at(i)->computeFitness(target);
  }

  vector<DNA *> pool = matingPool();


  for (int i = 0; i < (int)elements.size(); i++) {
    DNA * partnerA = pool.at(randInt(pool.size()));
    DNA * partnerB = pool.at(randInt(pool.size()));
    
    DNA * child = partnerA->crossover(partnerB);
    child->mutate(mutationRate);

    elements.at(i) = child;
  }

}

string Population::bestMatch() {
 
  float bestScore = 0;
  string best;
  for (int i = 0; i < (int)elements.size(); i++) {
    elements.at(i)->computeFitness(target);
    if (elements.at(i)->fitness > bestScore) {
      bestScore = elements.at(i)->fitness;
      best = elements.at(i)->getPhrase();
    }
  }
  return best;
}
