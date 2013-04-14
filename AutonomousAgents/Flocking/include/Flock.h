#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"

class Flock {
private:
  vector<Boid *> boids;
public:
  Flock() {
  }

  void run() {
    for(int i = 0; i < (int)boids.size(); i++) {
      boids.at(i)->flock(boids);
    }
  }

  void addBoid(Boid * b) {
    boids.push_back(b);
  }

  void draw() {
    for(int i = 0; i < (int)boids.size(); i++) {
      boids.at(i)->draw();
    }
  }
};


#endif
