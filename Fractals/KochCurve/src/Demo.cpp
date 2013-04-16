#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class KochLine {
private:
  Vec2f start;
  Vec2f end;
public:
  KochLine(Vec2f a, Vec2f b) {
    start = a;
    end = b;
  }

  void draw() {
    gl::color(Color(0, 0, 0));
    gl::drawLine(start, end);
  }

  Vec2f A() { return start; }
  Vec2f B() { return start + ((end - start) / 3); }
  Vec2f C() { 
    Vec2f rot = ((end - start) / 3);
    rot.rotate(-M_PI / 3);
    return start + ((end - start) / 3) + rot; 
  }
  Vec2f D() { return start + ((end - start) * 2.0 / 3); }
  Vec2f E() { return end; }
};

class Demo : public AppBasic {
private:
  vector<KochLine *> lines;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void cantor(Vec2f pos, float len);
  void generate();
};


void Demo::mouseDown(MouseEvent e) {
  generate();
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 600, 300 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();

  lines.push_back(new KochLine(Vec2f(0, 200), Vec2f(getWindowWidth(), 200)));
  for (int i = 0; i < 3; i++) {
    generate();
  }
}

void Demo::update() {
}

void Demo::generate() {
  vector<KochLine *> nextLines;

  for(int i = 0; i < (int)lines.size(); i++) {
    
    nextLines.push_back(new KochLine(lines.at(i)->A(), lines.at(i)->B()));
    nextLines.push_back(new KochLine(lines.at(i)->B(), lines.at(i)->C()));
    nextLines.push_back(new KochLine(lines.at(i)->C(), lines.at(i)->D()));
    nextLines.push_back(new KochLine(lines.at(i)->D(), lines.at(i)->E()));
  }
  lines = nextLines;
}

void Demo::draw() {
  gl::color( Color(1, 1, 1) );
  for (int i = 0; i < (int)lines.size(); i++) {
    lines.at(i)->draw();
  }
}

void Demo::cantor(Vec2f pos, float len) {
  gl::color( Color(0, 0, 0) );
  if (len >= 1) {
    gl::drawSolidRect(Rectf(pos, pos + Vec2f(len, 10)));
    cantor(pos + Vec2f(0, 20), len / 3);
    cantor(pos + Vec2f(len * 2.0/3, 20), len / 3);
  }
}

CINDER_APP_BASIC( Demo, RendererGl )
