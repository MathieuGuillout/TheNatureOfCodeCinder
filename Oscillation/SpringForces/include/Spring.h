#ifndef SPRING_H;
#define SPRING_H

#include "cinder/app/AppBasic.h"
#include "Mover.h"

class Spring {
private:
  ci::Vec2f anchor;
  float len;
  float k;
public:
  Spring( ci::Vec2f _anchor, float _len );
  void draw();
  void connect( Mover * mover );
  void drawLine( Mover * mover );
};
#endif
