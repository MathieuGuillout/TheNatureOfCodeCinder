#ifndef CLUSTER_H
#define CLUSTER_H

#include "Node.h"
#include "VerletPhysics.h"
#include <list>

class Cluster { 
private:
  std::vector<Node *> nodes;
  float diameter;
public:
  Cluster(VerletPhysics * physics, int n, float d, ci::Vec2f center);
  void draw();
};

#endif
