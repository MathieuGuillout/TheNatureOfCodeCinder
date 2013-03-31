#ifndef MOVER_H;
#define MOVER_H

#include "cinder/app/AppBasic.h"
using namespace ci;

class Mover {
private:
  Vec2f speed;
  Vec2f acceleration;
  float topSpeed;
  float damping;
  float mass;
  void checkEdges();
public:
  Mover( Vec2f _position );
  Vec2f position;
  float radius;
  void draw();
  void update();
  void drag( Vec2f position, Vec2f dragOffset );
  void applyForce( Vec2f force );
};
#endif
