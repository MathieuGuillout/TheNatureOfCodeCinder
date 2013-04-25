#include "World.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

World::World(int num) {
  
  for (int i = 0; i < num; i++) {
    Vec2f location = Vec2f(randFloat() * getWindowWidth() , randFloat() * getWindowHeight());
    DNA * dna = new DNA(1);
    bloops.push_back(new Bloop(location, dna));
  }
}

void World::update() {

  for(int i = bloops.size() - 1; i >= 0; i--) {

    Bloop * b = bloops.at(i);
    b->update();
    b->eat(foods);

    if (b->isDead()) {
      bloops.erase(bloops.begin() + i);
      foods.push_back(new Food(b->location));
    }

    Bloop * child = b->reproduce();
    if (child) {
      bloops.push_back(child);
    }
  }
}

void World::draw() {
  
  for(int i = bloops.size() - 1; i >= 0; i--) {
    bloops.at(i)->draw();
  }
  for(int i = foods.size() - 1; i >= 0; i--) {
    foods.at(i)->draw();
  }
}
