#include "Rocket.h"
#include "cinder/gl/gl.h"

using namespace ci;

Rocket::Rocket(int nbVectors, Vec2f t, DNA * d) {
  hitTarget = false;
  geneCounter = 0;
  target = t;
  dna = d;

  location = Vec2f(400, 400);
  velocity = Vec2f(0, 0);
  acceleration = Vec2f(0, 0);
}

void Rocket::applyForce(Vec2f f) {
  acceleration += f;
}

void Rocket::update() {
  velocity += acceleration;
  location += velocity;
  acceleration *= 0;
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
  gl::color(0.4, 0.4, 0.4, 0.1);
  gl::drawSolidCircle(location, 5);
}

void Rocket::computeFitness() {
  float d = (location - target).length();
  fitness = pow(1/d, 2);
}

void Rocket::checkTarget() {
  float d = (location - target).length();
  if ( d < 30 ) {
    hitTarget = true;
  }
}
