#include "Rocket.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Rocket::Rocket(int nbVectors, Vec2f t, DNA * d) {
  hitTarget = false;
  stopped = false;
  geneCounter = 0;
  target = t;
  dna = d;
  finishTime = 1;
  recordDist = 100000000;

  location = Vec2f(400, 400);
  velocity = Vec2f(0, 0);
  acceleration = Vec2f(0, 0);
}

void Rocket::applyForce(Vec2f f) {
  acceleration += f;
}

void Rocket::update() {
  if (!stopped) {
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
  }
}

void Rocket::run() {
  checkTarget(); 
  if (!hitTarget) {
    applyForce(dna->genes[geneCounter]);
    geneCounter++;
    update();
  }
}

void Rocket::draw() {
  gl::color(0, 1, 0, 0.7);
  gl::drawSolidCircle(location, 5);
}

void Rocket::computeFitness() {
  fitness = pow(1/(finishTime * (recordDist)), 2);
  if (stopped) fitness *= 0.3;
  if (hitTarget) fitness *= 2;
}

void Rocket::checkTarget() {
  float d = (location - target).length();
  if (d < recordDist) recordDist = d;
  if ( d < 30 ) {
    hitTarget = true;
  } else {
    finishTime++;
  }
}

void Rocket::checkObstacles(std::vector<Obstacle *> obstacles) {
  for (int i = 0; i < (int)obstacles.size(); i++) {
    if (obstacles.at(i)->contains(location)) {
      stopped = true;
    }
  }
}
