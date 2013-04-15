#ifndef CA_H
#define CA_H

#include <vector>
#include "cinder/app/AppBasic.h"

class CA {
private:
  std::vector<int> cells;
  std::vector<int> ruleset;
  ci::Vec2f size;
public:
  int resolution, generation;

  CA(ci::Vec2f size, int resolution);
  void draw();
  void generate();
  int rules(int a, int b, int c);
};

#endif
