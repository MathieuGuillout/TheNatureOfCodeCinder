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
  Vec2f velocity;
  Vec2f acceleration;

  float r;
  float maxSpeed;
  float maxForce;

public:
  Vec2f location;
  Vehicle(ci::Vec2f _location) {
    acceleration = Vec2f(0, 0);
    velocity = Vec2f(0, 0);
    location = _location;
    r = 13.0;
    maxSpeed = 10.0;
    maxForce = 0.1;
  }

  void update() {
    velocity += acceleration;
    velocity.limit(maxSpeed);
    location += velocity;
    acceleration *= 0;

    if (location.x < 0 || location.x > getWindowWidth()) {
      velocity.x *= -1;
      if (location.x < 0) location.x = 0;
      if (location.x > getWindowWidth()) location.x = getWindowWidth();
    }
    
    if (location.y < 0 || location.y > getWindowHeight()) {
      velocity.y *= -1;
      if (location.y < 0) location.y = 0;
      if (location.y > getWindowHeight()) location.y = getWindowHeight();
    }
  }

  void applyForce(ci::Vec2f force) {
    acceleration += force;
  }


  void separate(vector<Vehicle *> vehicles) {
    float desiredSeparation = r * 2;
    Vec2f sum = Vec2f(0, 0);
    int count = 0;
    for (int i = 0; i < (int)vehicles.size(); i++) {
      float d = (vehicles.at(i)->location - location).length();
      if (d > 0 && d < desiredSeparation) { 
        sum += (location - vehicles.at(i)->location).safeNormalized() / d;
        count++;
      }
    }

    if (count > 0) {
      sum /= count;
      sum.safeNormalize();
      sum *= maxSpeed;
      Vec2f steer = sum - velocity;
      steer.limit(maxForce);
      applyForce(steer);
    }

  }

  void draw() {
    color(Color(1, 0, 0));
    drawSolidCircle(location, r);
  }
};

#endif
