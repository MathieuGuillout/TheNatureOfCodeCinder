#ifndef VEHICLE_H
#define VEHICLE_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Shape2d.h"
#include "Path.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;

class Vehicle {
private:
  Vec2f location;
  Vec2f velocity;
  Vec2f acceleration;
  Shape2d shape;

  float r;
  float maxSpeed;
  float maxForce;

public:
  Vehicle(ci::Vec2f _location) {
    acceleration = Vec2f(0, 0);
    velocity = Vec2f(0, 0);
    location = _location;
    r = 4.0;
    maxSpeed = 4.0;
    maxForce = 0.1;

    shape = Shape2d();
    shape.moveTo( Vec2f(0, -r * 2) );
    shape.lineTo( Vec2f(-r, r * 2) );
    shape.lineTo( Vec2f(r, r * 2)  );
    shape.close();

  }

  void update() {
    velocity += acceleration;
    velocity.limit(maxSpeed);
    location += velocity;
    acceleration *= 0;
  }

  void applyForce(ci::Vec2f force) {
    acceleration += force;
  }


  Vec2f getNormalPoint(Vec2f p, Vec2f a, Vec2f b) {
    Vec2f ap = p - a;
    Vec2f ab = b - a;

    ab.normalize();
    ab *= ap.dot(ab);

    return a + ab;
  }

  void seek(Vec2f target) {
    Vec2f desired = target - location;
    desired.normalize();
    desired *= maxSpeed;

    Vec2f steer = desired - velocity;
    steer.limit(maxForce);
    applyForce(steer);
  }

  void follow(Path * p) {
    Vec2f predict = velocity;
    predict.safeNormalize();
    predict *= 25;
    Vec2f predictLoc = location + predict;

    Vec2f a = p->start;
    Vec2f b = p->end;
    Vec2f normalPoint = getNormalPoint(predictLoc, a, b);

    Vec2f dir = b - a;
    dir.normalize();
    dir *= 10;
    Vec2f target = normalPoint + dir;

    float distance = (normalPoint - predictLoc).length();
    if (distance > p->radius) {
      seek(target);
    }
  }

  void draw() {
    color(Color(1, 0, 0));

    pushMatrices();

    translate(location);
    rotate((atan2(velocity.normalized().y, velocity.normalized().x) + M_PI / 2) * 180.0/ M_PI);

    drawSolid(shape);

    popMatrices();
  }
};

#endif
