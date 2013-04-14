#ifndef VEHICLE_H
#define VEHICLE_H

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Shape2d.h"


using namespace ci;
using namespace ci::app;
using namespace ci::gl;
using namespace std;
using namespace boost;

class Boid {
private:
  Vec2f velocity;
  Vec2f acceleration;
  
  int resolution;
  float r;
  float maxSpeed;
  float maxForce;

public:
  Vec2f location;

  
  Boid(ci::Vec2f _location) {
    acceleration = Vec2f(0, 0);
    velocity = Vec2f(0, 0);
    location = _location;
    r = 2.0;
    maxSpeed = 5.0;
    maxForce = 0.1;

    resolution = 10;
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


  void flock(vector<Boid *> boids) {
    Vec2f sep = separate(boids);
    Vec2f ali = align(boids);
    Vec2f coh = cohesion(boids);

    sep *= 1.5;
    ali *= 1.0;
    coh *= 1.0;

    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
    update();
  }

  Vec2f separate(vector<Boid *> vehicles) {
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

    Vec2f steer = Vec2f(0, 0);
    if (count > 0) {
      sum /= count;
      sum.safeNormalize();
      sum *= maxSpeed;
      steer = sum - velocity;
      steer.limit(maxForce);
    }
    
    return steer;
  }

  Vec2f align(vector<Boid *> boids) {
    Vec2f sum = Vec2f(0, 0);
    for(int i = 0; i < (int)boids.size(); i++) {
      sum += boids.at(i)->velocity;
    }
    sum /= boids.size();
    sum = sum.safeNormalized() * maxSpeed;

    Vec2f steer = sum - velocity;
    steer.limit(maxForce);
    
    return steer;
  }

  Vec2f cohesion(vector<Boid *> boids) {
    float neighborDist = 50;

    Vec2f sum = Vec2f(0, 0);
    int count = 0;
    for(int i = 0; i < (int)boids.size(); i++) {
      float d = (location - boids.at(i)->location).length();
      if (d > 0 && d < neighborDist) {
        sum += boids.at(i)->location;
        count++;
      }
    }

    Vec2f result = Vec2f(0, 0);
    if (count > 0) {
      sum /= count;
      result = seek(sum);
    }
    return result;
  }

  Vec2f seek(Vec2f target) {
    ci::Vec2f desired = target - location;
    desired.normalize();
    desired *= maxSpeed;

    ci::Vec2f steer = desired - velocity;
    steer.limit(maxForce);
    return steer;
  }

  void draw() {
    color(Color(1, 0, 0));
    drawSolidCircle(location, r);
  }
};

#endif
