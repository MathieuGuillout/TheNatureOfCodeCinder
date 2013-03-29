#include "cinder/app/AppBasic.h"
using namespace ci;

class Ball {
private:
  Vec2f position;
  Vec2f speed;
public:
  Ball();
  void draw();
  void update();
};
