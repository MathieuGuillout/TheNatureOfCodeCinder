#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class Line {
public:
  Vec2f start, end;
  Line(Vec2f s, Vec2f e) {
    start = s;
    end = e;
  }
};

class Tree {
public:
  vector< vector<Line *> > branches;
  Tree(Vec2f root, float len, float theta, int generations);
  void draw();
};

Tree::Tree(Vec2f root, float len, float theta, int generations) {
  vector<Line *> first_branches;
  first_branches.push_back(new Line(Vec2f(0, 0), Vec2f(0, len)));
  this->branches.push_back(first_branches);
}

void Tree::draw() {
    console() << this->branches.size() << endl;
    /*
    for(int i = 0; i < (int)(branches.size()); i++) {
      vector<Line *> brs = branches.at(i);
      for(int j = 0; j < (int)brs.size(); j++) {
        //gl::drawLine(brs.at(j)->start, brs.at(j)->end);
      }
    }
    */
}

class Demo : public AppBasic {
public:
  Tree * tree;
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void branch(float len);
};


void Demo::mouseDown(MouseEvent e) {}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 600, 300 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();

  Tree * tree = new Tree(Vec2f(getWindowWidth() / 2, 0), 30, M_PI / 3, 10);
  console() << tree->branches.size() << endl;
}

void Demo::update() {
}

void Demo::draw() {
  gl::color( Color(1, 1, 1) );
  //tree->draw();
  console() << tree->branches.size() << endl;
}

CINDER_APP_BASIC( Demo, RendererGl )
