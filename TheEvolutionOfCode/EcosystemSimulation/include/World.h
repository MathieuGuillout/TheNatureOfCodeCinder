#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Bloop.h"
#include "Food.h"

class World {
private:
  std::vector<Bloop *> bloops;
  std::vector<Food *> foods;

public:
  World(int num);
  void update();
  void draw();
};


#endif
