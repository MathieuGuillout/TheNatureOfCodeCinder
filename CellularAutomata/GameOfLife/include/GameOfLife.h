#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include "cinder/app/AppBasic.h"

class GameOfLife {
private:
  int columns, rows, resolution;
  int **board;
  
public:
  GameOfLife(ci::Vec2f size, int resolution);
  void generate();
  void draw();
};

#endif
