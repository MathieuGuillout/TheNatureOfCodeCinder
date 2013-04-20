#include "DNA.h"
#include "cinder/Rand.h"
#include "cinder/app/AppBasic.h"

using namespace std;
using namespace ci;
using namespace ci::app;

DNA::DNA(int nbGenes, float maxForce) {
  for (int i = 0; i < nbGenes; i++) {
    genes.push_back(randVec2f() * randFloat(maxForce));
  }
}

