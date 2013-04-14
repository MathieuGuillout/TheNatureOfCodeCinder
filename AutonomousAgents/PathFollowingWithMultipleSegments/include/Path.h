#ifndef PATH_H
#define PATH_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Shape2d.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class Path {

public:
  vector<Vec2f> points;
  Shape2d shape;
  float radius;

  Path() {
    radius = 15;
  }

  void addPoint(Vec2f point) {

    points.push_back(point);

    int nbPoints = (int)points.size();

    if (nbPoints >= 2) {
      shape = Shape2d();
      shape.moveTo(points.at(0) + Vec2f(0, radius));
      for (int i = 0; i < nbPoints; i++) {
        shape.lineTo( points.at(i) + Vec2f(0, radius) );
      }
      for (int i = nbPoints - 1; i >= 0; i--) {
        shape.lineTo( points.at(i) + Vec2f(0, -radius) );
      }
      shape.close();
    }

  }

  void draw() {
    gl::color(Color(0.4, 0.4, 0.4));
    gl::drawSolid(shape);
  }
};

#endif
