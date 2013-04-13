#ifndef VEHICLE_H
#define VEHICLE_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Path.h"

using namespace ci;
using namespace ci::app;
using namespace ci::gl;

class Vehicle {
private:
  ci::Vec2f location;
  ci::Vec2f velocity;
  ci::Vec2f acceleration;

  float r;
  float maxSpeed;
  float maxForce;

public:
  Vehicle(ci::Vec2f _location) {
    acceleration = ci::Vec2f(0, 0);
    velocity = ci::Vec2f(0, 0);
    location = _location;
    r = 4.0;
    maxSpeed = 4.0;
    maxForce = 0.1;
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


  Vec2f getNormalPoint(Vec2f v1, Vec2f v2, Vecf v3) {
    
    Vec2f a = v1 - v2;
    Vec2f b = v3 - v2; 
    b.normalize();
    b *= (a * b);
    return v2 + b;

  }

  void follow(Path * p) {
    Vec2f predict = velocity.normalized() * 25;
    Vec2f predictLoc = location + predict;

    Vec2f a = p->start;
    Vec2f b = p->end;
    Vec2f normalPoint = getNormalPoint(predict, a, b);

    Vec2f dir = b - a;
    dir.normalize();
    dir *= 10;
    Vec2f target = normalPoint + dir;

    float distance = normalPoint - predictLoc;
    if (distance > p->radius) {
      seek(target);
    }
  }

  void draw() {
    color(Color(1, 0, 0));
    pushMatrices();

    translate(location);
    rotate((atan2(velocity.normalized().y, velocity.normalized().x) + M_PI / 2) * 180.0/ M_PI);

    drawLine(Vec2f(0, -r * 2), Vec2f(-r, r * 2));
    drawLine(Vec2f(-r, r * 2), Vec2f(r, r * 2));
    drawLine(Vec2f(r, r * 2), Vec2f(0, -r * 2));

    popMatrices();
  }
};

#endif
