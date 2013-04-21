#include "DNA.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

DNA::DNA() {
  len = 10;
  for (int i = 0; i < len; i++) {
    genes.push_back(randFloat());
  }
}

DNA::DNA(vector<float> gs) {
  len = 10;
  genes = gs;
}

DNA * DNA::crossover(DNA * partner) {

  vector<float> child;

  int crossover = randInt((int)genes.size());
  for (int i = 0; i < (int)genes.size(); i++) {
    if (i > crossover) {
      child.push_back(genes.at(i));
    } else {
      child.push_back(partner->genes.at(i)); 
    }
  }

  return new DNA(child);

}

void DNA::mutate(float mutationRate) {
  
  for (int i = 0; i < (int)genes.size(); i++) {
    if (randFloat(1) < mutationRate) {
      genes.at(i) = randFloat();
    }
  }
}
