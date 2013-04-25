#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"
#include "Population.h"
#include "DNA.h"
#include "Face.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Population::Population(float _mutationRate, int _nbElts) {
  mutationRate = _mutationRate;
  for (int i = 0; i < _nbElts; i++) {
    elements.push_back(new Face(new DNA(), Vec2f(50 + i * 85, 60)));
  }
}



void Population::selection() {

  matingPool.clear();

  float maxFitness = getMaxFitness();
  for (int i = 0; i < (int)elements.size(); i++) {

    float fitnessNormal = lmap(elements.at(i)->fitness, 0.0f, maxFitness, 0.0f, 1.0f);
    int n = (int)(fitnessNormal * 100);
    for (int j = 0; j < n; j++) {
      matingPool.push_back(elements.at(i));
    }
  }

}

void Population::reproduction() {


  for (int i = 0; i < (int)elements.size(); i++) {
    DNA * partnerA = matingPool.at(randInt(matingPool.size()))->dna;
    DNA * partnerB = matingPool.at(randInt(matingPool.size()))->dna;
    
    DNA * child = partnerA->crossover(partnerB);
    child->mutate(mutationRate);

    elements.at(i) = new Face(child, Vec2f(50 + i * 85, 60));
  }

}

float Population::getMaxFitness() {
  float record = 0;
  for (int i = 0; i < (int)elements.size(); i++) {
    if (elements.at(i)->fitness > record) {
      record = elements.at(i)->fitness;
    }
  }
  return record;
}

void Population::draw() {
  for (int i = 0; i < (int)elements.size(); i++) {
    elements.at(i)->draw();
  }
}

void Population::rollover(Vec2f pos) {
  for (int i = 0; i < (int)elements.size(); i++) {
    elements.at(i)->rollover(pos);
  }
}
