#ifndef FLOWFIELD_H
#define FLOWFIELD_H

#include "cinder/app/AppBasic.h"
#include "cinder/Perlin.h"
#include "cinder/gl/gl.h"
#include <vector>

using namespace std;
using namespace ci;

class FlowField {
private: 
  vector< vector<Vec2f> > field;  
  int cols, rows;
  int resolution;
  Vec2f size;
public:
  FlowField(Vec2f _size) {
    resolution = 30;
    size = _size;
    cols = size.x / resolution;
    rows = size.y / resolution;

    Perlin mPerlin = Perlin();
    mPerlin.setSeed(time(0));
  
    float xoff = 0;
    for (int i = 0; i < cols; i++) {
      float yoff = 0;
      vector<Vec2f> col;
      for (int j = 0; j < rows; j++) {
        float theta = lmap((float)mPerlin.noise(xoff, yoff), 0.0f, 1.0f, 0.0f, (float)M_PI * 2.0f);
        col.push_back(Vec2f(cos(theta), sin(theta)));
        yoff += 0.1;
      }
      xoff += 0.1;
      field.push_back(col);
    }
  }

  Vec2f lookup(Vec2f lookup) {
    int column = (int)constrain((int)(lookup.x / resolution), 0, cols - 1);
    int row = (int)constrain((int)(lookup.y / resolution), 0, rows - 1);
    //return Vec2f(0, 0);
    return field.at(column).at(row);
  }

  void draw() {
    gl::color(Color(0, 0, 0));

    for (int i = 0; i < (int)field.size(); i++) {
      vector<Vec2f> col = field.at(i);
      for(int j = 0; j < (int)col.size(); j++) {
        Vec2f fl = col.at(j);
        Vec2f origin = Vec2f(i * 1.0f * resolution, j * 1.0f * resolution);
        gl::drawLine(origin, origin + fl * resolution / 2);
      }
    }
  }
};

#endif
