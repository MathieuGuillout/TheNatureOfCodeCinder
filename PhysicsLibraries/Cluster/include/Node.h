#ifndef NODE_H
#define NODE_H

#include "cinder/app/AppBasic.h"
#include "VerletParticle.h"

class Node : public VerletParticle {
public:
  Node(ci::Vec2f pos);
  void draw();
};

#endif
