#ifndef FACE_H
#define FACE_H

#include "DNA.h"

class Face {
public:
  DNA * dna;
  float fitness;

  Face();
  void draw();
};

#endif
