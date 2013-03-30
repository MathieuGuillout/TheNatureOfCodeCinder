#include "cinder/app/AppBasic.h"
using namespace ci;

class Ball {
private:
  Vec2f position;
  Vec2f speed;
  Vec2f acceleration;
  float mass;
  float topSpeed;
public:
  Ball(float m, Vec2f pos);
  void applyForce(Vec2f force);
  void checkEdges();
  void draw();
  void update();
};
