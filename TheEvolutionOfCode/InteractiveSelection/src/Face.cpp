#include "Face.h"
#include "cinder/gl/gl.h"

using namespace ci;

Face::Face() {
  
}

void Face::draw() {
  
  float r = lmap(dna->genes.at(0), 0.0f, 1.0f, 0.0f, 70.f);

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
  
}
