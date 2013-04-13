#ifndef VEHICLE_H
#define VEHICLE_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

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
    r = 10.0;
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

  void arrive(Vec2f target) {
    Vec2f desired = target - location;
    float d = desired.length();
    desired.normalize();

    if ( d < 100) {
      float m = lmap(d, 0.0f, 100.0f, 0.0f, maxSpeed);
      desired *= m;
    } else {
      desired *= maxSpeed;
    }

    Vec2f steer = desired - velocity;
    steer.limit(maxForce);
    applyForce(steer);
  }

  void draw() {
    color(Color(0, 0, 0));
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
