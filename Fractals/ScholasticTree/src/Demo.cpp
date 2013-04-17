#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class Branch {
public:
  Vec2f start;
  Vec2f end;
  Branch(Vec2f s, Vec2f e) {
    start = s;
    end = e;
  }
};

class Tree {
public:
  vector< vector<Branch *> > branches;
  float len;
  Tree(Vec2f root, float _len, int generations) {
    len = _len;
    vector<Branch *> first_branches;
    first_branches.push_back(new Branch(Vec2f(getWindowWidth() / 2, getWindowHeight()), 
                                        Vec2f(getWindowWidth() / 2, getWindowHeight() - len)));
    branches.push_back(first_branches);

    for(int i = 0; i < generations; i++) {
      generate();
    }
  }

  void generate() {
    len *= 0.7;
    vector<Branch *> newBranches;
    vector<Branch *> lastGroup = branches.at(branches.size() - 1);
    for(int i = 0; i < (int)(lastGroup.size()); i++) {
      Branch * b = lastGroup.at(i);

      int n = randInt(1, 4);
      for (int j = 0; j < n; j++) {
        Vec2f b1 = (b->end - b->start).safeNormalized() * len;
        b1.rotate(randFloat(-M_PI/2, M_PI/2));
        newBranches.push_back(new Branch(b->end, b->end + b1)); 
      }

    }
    branches.push_back(newBranches);
  }

  void draw() {
    gl::color(Color(0, 0, 0));
    for(int i = 0; i < (int)(branches.size()); i++) {
      vector<Branch *> brs = branches.at(i);
      for(int j = 0; j < (int)brs.size(); j++) {
        gl::drawLine(brs.at(j)->start, brs.at(j)->end);
      }
    }
  }

};

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

  Rand::randomize();
  tree = new Tree(Vec2f(getWindowWidth() / 2, 0), 90, 10);
}

void Demo::update() {
}

void Demo::draw() {
  gl::color( Color(1, 1, 1) );
  tree->draw();
}

CINDER_APP_BASIC( Demo, RendererGl )
