#ifndef MOVER_H;
#define MOVER_H

#include "cinder/app/AppBasic.h"

class Mover {
private:
  ci::Vec2f speed;
  ci::Vec2f acceleration;
  float topSpeed;
  float damping;
  float mass;
public:
  Mover( ci::Vec2f _position );
  ci::Vec2f position;
  float radius;
  void draw();
  void update();
  void drag( ci::Vec2f position, ci::Vec2f dragOffset );
  void applyForce( ci::Vec2f force );
};
#endif
