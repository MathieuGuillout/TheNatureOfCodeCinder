#include "cinder/app/AppBasic.h"
using namespace ci;

class Ball {
private:
  Vec2f position;
  Vec2f speed;
  Vec2f acceleration;
  float topSpeed;
public:
  Ball(float m, Vec2f pos);
  float mass;
  void applyForce(Vec2f force);
  void checkEdges();
  void draw();
  void update();
};
