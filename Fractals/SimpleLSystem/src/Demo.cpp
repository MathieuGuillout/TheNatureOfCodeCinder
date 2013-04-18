#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>
#include <stack>

using namespace ci;
using namespace ci::app;
using namespace std;

class Rule {
public:
  char key;
  string next;
  Rule(char k, string s) {
    key = k;
    next = s;
  }
};

class Line {
public:
  Vec2f start, end;
  Line(Vec2f s, Vec2f e) {
    start = s;
    end = e;
  }
};


class State {
public:
  Vec2f position;
  float angle;
  State(Vec2f p, float a) {
    position = p;
    angle = a;
  }
};

class Turtle {
public:
  string sentence;
  float len;
  float theta;
  Vec2f startPoint;
  vector<Line *> lines;
  Turtle(string _sentence, float _len, float _theta, Vec2f start) {
    sentence = _sentence;
    len = _len;
    theta = _theta;
    startPoint = start;
  }

  void draw() {

    gl::color(0.2, 0.2, 0.2, 0.5);
    for(int i = 0; i < (int)lines.size(); i++) {
      gl::drawLine(lines.at(i)->start, lines.at(i)->end);
    }

  }

  void generateLines() {
    Vec2f lastPoint = startPoint;
    float lastAngle = 0;
    vector<Line *> newlines;
    stack<State *> states;


    for(int i = 0; i < (int)sentence.length(); i++) {
      char c = sentence.at(i);
      Vec2f add = Vec2f(0, -len);
      add.rotate(lastAngle);
      Vec2f endPoint;

      switch (c) {
        case 'F': 
          endPoint = lastPoint + add;
          newlines.push_back(new Line(lastPoint, endPoint));
          lastPoint = endPoint;
          break;
        case 'G':
          lastPoint = lastPoint + add;
          break;
        case '+':
          lastAngle += theta;
          break;
        case '-':
          lastAngle -= theta;
          break;
        case '[':
          states.push(new State(lastPoint, lastAngle));
          break;
        case ']':
          State * state = states.top();
          lastPoint = state->position;
          lastAngle = state->angle;
          states.pop();
          break;
      }
    }

    lines = newlines;
  }
  void setToDo(string _sentence) {
    sentence = _sentence;
    generateLines();
  }
  void changeLen(float _f) {
    len *= _f;
  }
};

class LSystem {
public:
  string sentence;
  vector<Rule *> rules;
  LSystem(string init, vector<Rule *> rs) {
    sentence = init;
    rules = rs;
  }

  void generate() {
    stringstream next;
    next << "";

    for(int i = 0; i < (int)sentence.length(); i++) {
      
      char c = sentence.at(i);
      bool found = false;
      for (int j = 0; j < (int)rules.size(); j++) {
        Rule * rule = rules.at(j);
        if (rule->key == c) {
          next << rule->next;
          found = true;
          break;
        }
      }

      if (!found) {
        next << c;
      }

    }
    sentence = next.str();
  }
};

class Demo : public AppBasic {
private:
  LSystem * lsystem;
  Turtle * turtle;
public:
  void prepareSettings( Settings *settings );
  void setup();
  void draw();
  void update();
  void mouseDown(MouseEvent e);
  void branch(float len);
};


void Demo::mouseDown(MouseEvent e) {
  turtle->changeLen(0.5f);
  turtle->setToDo(lsystem->sentence);
  lsystem->generate();
}

void Demo::prepareSettings(Settings *settings) {
  settings->setWindowSize( 500, 600 );
  settings->setFrameRate( 60.0f );
}

void Demo::setup() {

  gl::clear( Color(1, 1, 1) );
  gl::enableAlphaBlending();

  vector<Rule *> rules;
  rules.push_back(new Rule('F', string("FF+[+F-F-F]-[-F+F+F]")));
  lsystem = new LSystem(string("F"), rules);
  turtle = new Turtle(
    lsystem->sentence, 
    getWindowHeight() / 2, 
    M_PI/7, 
    Vec2f(getWindowWidth() / 2, getWindowHeight())
  );

}

void Demo::update() {
}

void Demo::draw() {
  gl::color( Color(1, 1, 1) );
  turtle->draw();
}

CINDER_APP_BASIC( Demo, RendererGl )
