#include "GameOfLife.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

GameOfLife::GameOfLife(Vec2f size, int _res) {

  Rand::randomize();

  resolution = _res;
  columns = (int)(size.x / resolution);
  rows = (int)(size.y / resolution);

  board = new int*[columns];
  for(int x = 0; x < columns; x++) {
    board[x] = new int[rows];
    for(int y = 0; y < rows; y++) {
      board[x][y] = randInt(2);
    }
  }
}

void GameOfLife::generate() {
 
  int **next;
 
  next = new int*[columns];
  
  next[0] = board[0];
  next[columns - 1] = board[columns - 1];

  for(int x = 1; x < columns - 1; x++) {
    next[x] = new int[rows];
    next[x][0] = board[x][0];
    next[x][rows - 1] = board[x][rows - 1];

    for(int y = 1; y < rows - 1; y++) {
      int neighbors = 0;

      for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
          neighbors += board[x+i][y+j];
        }
      }
      neighbors -= board[x][y];

      if      (board[x][y] == 1 && neighbors <  2) next[x][y] = 0;
      else if (board[x][y] == 1 && neighbors >  3) next[x][y] = 0;
      else if (board[x][y] == 0 && neighbors == 3) next[x][y] = 1;
      else next[x][y] = board[x][y];
      
    }
  }
  board = next;
}

void GameOfLife::draw() {
  for(int i = 0; i < columns; i++) {
    for(int j = 0; j < rows; j++) {
      gl::color( board[i][j] == 1 ? Color(0, 0, 0) : Color(1, 1, 1) );
      gl::drawSolidRect(Rectf(
        i * resolution,
        j * resolution,
        (i + 1) * resolution,
        (j + 1) * resolution
      ));
    }
  }
}
