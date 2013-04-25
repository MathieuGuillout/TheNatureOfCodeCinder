#include "Face.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include <sstream>

using namespace ci;
using namespace ci::app;
using namespace std;

Face::Face(DNA * _dna, Vec2f _position) {
  dna = _dna;
  position = _position;
  fitness = 1.0f;

}

void Face::draw() {

  float r = lmap(dna->genes.at(0), 0.0f, 1.0f, 0.0f, 40.f);

  Color c = Color(dna->genes.at(1), dna->genes.at(2), dna->genes.at(3));
  float eye_y = lmap(dna->genes.at(4), 0.0f, 1.0f, 0.0f, 5.0f);
  float eye_x = lmap(dna->genes.at(5), 0.0f, 1.0f, 0.0f, 10.0f);
  float eye_size = lmap(dna->genes.at(5), 0.0f, 1.0f, 0.0f, 10.0f);
  Color eye_color = Color(dna->genes.at(4), dna->genes.at(5), dna->genes.at(6));
  Color mouth_color = Color(dna->genes.at(7), dna->genes.at(8), dna->genes.at(9));
  float mouth_y = lmap(dna->genes.at(5), 0.0f, 1.0f, 0.0f, 25.0f);
  float mouth_x = lmap(dna->genes.at(5), 0.0f, 1.0f, -25.0f, 25.0f);
  float mouth_w = lmap(dna->genes.at(5), 0.0f, 1.0f, 0.0f, 50.0f);
  float mouth_h = lmap(dna->genes.at(5), 0.0f, 1.0f, 0.0f, 10.0f);

  gl::pushMatrices();
  gl::translate(position); 

  // Draw the head
  gl::color(c);
  gl::drawSolidCircle(Vec2f(0, 0), r);

  // Draw the eyes
  gl::color(eye_color);
  gl::drawSolidRect(Rectf(Vec2f(-eye_x, -eye_y), Vec2f(-eye_x + eye_size, -eye_y + eye_size)));
  gl::drawSolidRect(Rectf(Vec2f(eye_x, -eye_y), Vec2f(eye_x + eye_size, -eye_y + eye_size)));

  // Draw the mouth
  gl::color(mouth_color);
  gl::drawSolidRect(Rectf(Vec2f(mouth_x, mouth_y), Vec2f(mouth_x + mouth_w, mouth_y + mouth_h)));

  // Draw the bounding box
  gl::color(Color(0, 0, 0));
  gl::drawStrokedRect(Rectf(Vec2f(-35, -35), Vec2f(35, 35)));

  std::stringstream st;
  st << (int)fitness;
  gl::drawString(st.str(), Vec2f(35, 35),ColorA(0,0,0,1), Font("Arial", 15));

  gl::popMatrices();
}

void Face::rollover(ci::Vec2f pos) {
  if (Rectf(position + Vec2f(-35, -35), position + Vec2f(35, 35)).contains(pos)) {
    fitness += 0.25;
  }
}
