#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

class GameOfLife {
private:
  int columns, rows, resolution;
  int **board;
  
public:
  GameOfLife();
  void generate();
  void draw();
};

#endif
