#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Particle.h"
#include "VerletPhysics.h"

class Chain {
private:
  float totalLength;
  int numPoints;
  float strength;
  float radius;
  std::vector<Particle *> particles;
  Particle * tail;

  Vec2f offset;
  bool dragged;

public:
  Chain(VerletPhysics * physics, float l, int n, float r, float s);
  void contains(ci::Vec2f pos);
  void release();
  void updateTail(ci::Vec2f pos);
  void draw();
};

#endif
