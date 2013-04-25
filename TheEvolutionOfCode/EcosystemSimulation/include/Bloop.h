#ifndef BLOOP_H
#define BLOOP_H

#include "cinder/Vector.h"
#include "cinder/Perlin.h"
#include "Food.h"
#include "DNA.h"

class Bloop {
private:
  float r;
  float maxspeed;
  float xoff, yoff;
  float health;
  ci::Perlin * perlin;
  DNA * dna;

public:
  Bloop(ci::Vec2f pos, DNA * _dna);

  ci::Vec2f location;

  void update();
  void draw();
  void eat(std::vector<Food *> foods);
  bool isDead();
  Bloop * reproduce();
};


#endif
