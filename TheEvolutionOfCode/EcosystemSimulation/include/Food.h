#ifndef FOOD_H
#define FOOD_H

#include "cinder/Vector.h"

class Food {
public:
  ci::Vec2f location;
  Food(ci::Vec2f location);
  void draw();
};

#endif
