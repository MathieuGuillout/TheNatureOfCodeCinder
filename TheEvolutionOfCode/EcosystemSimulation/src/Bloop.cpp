#include "Bloop.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std; 

Bloop::Bloop(Vec2f pos, DNA * _dna) {
  location = pos;
  health = 200;
  dna = _dna;

  perlin = new Perlin();
  xoff = randFloat(-1000, 1000); 
  yoff = randFloat(-1000, 1000);
  maxspeed = lmap<float>(dna->genes[0], 0, 1, 15, 0);
  r        = lmap<float>(dna->genes[0], 0, 1, 0, 50);
}

void Bloop::update() {

  float vx = lmap<float>(perlin->noise(xoff), 0, 1, -maxspeed, maxspeed);
  float vy = lmap<float>(perlin->noise(yoff), 0, 1, -maxspeed, maxspeed);
  console() << " VX " << vx << " VY " << vy << endl;
  Vec2f velocity = Vec2f(vx, vy);

  xoff += 0.1;
  yoff += 0.1;
  location += velocity;

  health -= 0.2;

  if (location.x < 0) {
    location.x = 0;
    velocity.x *= -1;
  }
  if (location.x > getWindowWidth() ) {
    location.x = getWindowWidth();
    velocity.x *= -1;
  }
  if (location.y < 0) {
    location.y = 0;
    velocity.y *= -1;
  }
  if (location.y > getWindowHeight()) {
    location.y = getWindowHeight();
    velocity.y *= -1;
  }
}

void Bloop::draw() {
  gl::color(Color(0, 0, 0));
  gl::drawSolidCircle(location, r);
}

void Bloop::eat(vector<Food *> food) {

  for (int i = food.size() - 1; i >= 0; i++) {
    Food * f = food.at(i);
    float d = (location - f->location).length();
    if ( d < r/2) {
      health += 100;
      food.erase(food.begin() + i);
    }
  }
}

bool Bloop::isDead() {
  return health < 0;
}

Bloop * Bloop::reproduce() {
  if (randFloat() < 0.0005) {
    DNA * childDNA = dna->copy();
    childDNA->mutate(0.01);
    return new Bloop(location, childDNA);
  } else {
    return 0;
  }
}
