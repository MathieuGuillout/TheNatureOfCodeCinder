#include "Rocket.h"
#include "cinder/gl/gl.h"

using namespace ci;

Rocket::Rocket(int nbVectors) {
  geneCounter = 0;
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
  applyForce(dna->genes[geneCounter]);
  geneCounter++;
  update();
}

void Rocket::draw() {
  gl::color(Color(0, 0, 0));
  gl::drawSolidCircle(position, 5);
}
