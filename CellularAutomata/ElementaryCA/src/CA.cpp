#include <boost/assign/std/vector.hpp> 
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "CA.h"
#include <sstream>

using namespace boost::assign;
using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;


CA::CA(Vec2f _size, int _resolution) {

  resolution = _resolution;
  generation = 0;
  size = _size;

  ruleset += 0, 1, 1, 0, 1, 1, 0, 1;
  for (int i = 0; i < (int)(size.x / resolution); i++) {
    cells.push_back(0);
  }

  cells.at((int)(cells.size() / 2)) = 1;
}

void CA::draw() {

  for (int i = 0; i < (int)cells.size(); i++) {
    color(cells.at(i) == 0 ? Color(1, 1, 1) : Color(0, 0, 0));
    drawSolidRect(Rectf(i * resolution, 
                        generation * resolution, 
                        (i + 1) * resolution, 
                        ( generation + 1 ) * resolution));
  }
}

void CA::generate() {
  vector<int> newCells;

  newCells.push_back(cells.at(0));
  for (int i = 1; i < (int)cells.size() - 1; i++) {
    int left = cells.at(i - 1);
    int middle = cells.at(i);
    int right = cells.at(i + 1);

    int newstate = rules(left, middle, right);
    newCells.push_back(newstate);
  }
  newCells.push_back(cells.at(cells.size() - 1));

  cells = newCells;
  generation++;
}

int CA::rules(int a, int b, int c) {
  std::stringstream ss;
  ss << a << b << c ;
  int index = strtol(ss.str().c_str(), 0, 2); 
  return ruleset.at(index);
}
