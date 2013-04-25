#ifndef FACE_H
#define FACE_H

#include "cinder/Vector.h"
#include "DNA.h"

class Face {
public:
  DNA * dna;
  float fitness;
  ci::Vec2f position;

  Face(DNA * dna, ci::Vec2f position);
  void draw();
  void rollover(ci::Vec2f position);
};

#endif
