#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"
#include "boost/tuple/tuple.hpp"
#include <boost/tuple/tuple_comparison.hpp>
#include <map>
#include <vector>

using namespace boost;
using namespace std;

class Flock {
private:
  vector<Boid *> boids;
  int resolution;

public:
  map< tuple<int, int> , vector< Boid * > > grid;

  Flock() {
    resolution = 20; 
  }

  void run() {
    for(int i = 0; i < (int)boids.size(); i++) {
      boids.at(i)->flock(grid[getBoidKey(boids.at(i))]);
    }
  }

  tuple<int, int> getBoidKey(Boid * boid) {
    Vec2f pos = boid->location;
    return tuple<int, int>((int)pos.x / resolution, (int)pos.y / resolution);
  }

  void addBoid(Boid * b) {
    boids.push_back(b);
  }

  void initGrid() {
    for (int i = 0; i < getWindowWidth(); i += resolution) {
      for (int j = 0; j < getWindowHeight(); j += resolution) {
        tuple<int, int> key = tuple<int, int>(i, j);
        grid[key] = vector<Boid *>();
      }
    }
    for(int i = 0; i < (int)boids.size(); i++) {
      grid[getBoidKey(boids.at(i))].push_back(boids.at(i));
    }
  }

  void draw() {
    for(int i = 0; i < (int)boids.size(); i++) {
      boids.at(i)->draw();
    }
    initGrid();
  }
};


#endif
