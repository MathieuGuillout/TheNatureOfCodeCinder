#include "cinder/app/AppBasic.h"
using namespace ci;

class Ball {
private:
  Vec2f position;
  Vec2f speed;
  Vec2f acceleration;
  float topSpeed;
  void checkEdges();
public:
  Ball();
  void draw();
  void update(Vec2f target);
};
