#include "GameOfLife.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

GameOfLife::GameOfLife() {

  columns = 3;
  rows = 3;
  resolution = 100;

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
  for(int x = 1; x < columns - 1; x++) {
    next[x] = new int[rows];
    for(int y = 1; y < rows - 1; y++) {
     
      int neighbors = 0;

      for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
          neighbors += board[x+i][y+j];
        }
      }
      neighbors -= board[x][y];
      console() << x << " = " <<  y << endl;
      console() << " NEIGHBORS " << neighbors << endl;

      if      (board[x][y] == 1 && neighbors <  2) next[x][y] = 0;
      else if (board[x][y] == 1 && neighbors >  3) next[x][y] = 0;
      else if (board[x][y] == 0 && neighbors == 3) next[x][y] = 1;
      else next[x][y] = board[x][y];
    }
  }
  console() << "BEFORE NEXT" << endl;
  board = next;
  console() << "AFTER NEXT" << endl;
}

void GameOfLife::draw() {

  console() << " BEGIN DRAW " << endl;
  for(int i = 0; i < columns; i++) {
    for(int j = 0; j < rows; j++) {
      console() << " DRAW " << i << " + " << j << endl;
      gl::color( board[i][j] == 1 ? Color(0, 0, 0) : Color(1, 1, 1) );
      gl::drawSolidRect(Rectf(
        i * resolution,
        j * resolution,
        (i + 1) * resolution,
        (j + 1) * resolution
      ));
    }
  }
  console() << " END DRAW " << endl;
}
