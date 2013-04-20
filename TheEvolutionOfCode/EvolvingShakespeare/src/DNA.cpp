#include "DNA.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

DNA::DNA(int nbGenes) {
  for (int i = 0; i < nbGenes; i++) {
    char letter = (char) (randInt(20, 140));
    genes.push_back(letter);
  }
}

void DNA::computeFitness(string target) {
  int score = 0;
  for (int i = 0; i < (int)genes.size(); i++) {
    if (genes.at(i) == target.at(i)) {
      score++;
    }
  }
  fitness = (float) score / target.length();
}

DNA * DNA::crossover(DNA * partner) {
  DNA * child = new DNA(genes.size());
  int midPoint = randInt(genes.size());
  for (int i = 0; i < (int)genes.size(); i++) {
    if (i > midPoint) {
      child->genes.at(i) = genes.at(i);
    } else {
      child->genes.at(i) = partner->genes.at(i);
    }
  }
  return child;
}

void DNA::mutate(float mutationRate) {
  for(int i = 0; i < (int)genes.size(); i++) {
    if (randFloat(1) < mutationRate) {
      genes.at(i) = (char)(randInt(20, 140));
    }
  }
}

string DNA::getPhrase() {
  return string(genes.begin(),genes.end());
}
