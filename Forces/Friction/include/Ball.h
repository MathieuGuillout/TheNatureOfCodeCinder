#include "cinder/app/AppBasic.h"
using namespace ci;

class Ball {
private:
  float topSpeed;
  Vec2f position;
  Vec2f acceleration;
public:
  Ball(float m, Vec2f pos);
  float mass;
  Vec2f speed;
  void applyForce(Vec2f force);
  void checkEdges();
  void draw();
  void update();
};
