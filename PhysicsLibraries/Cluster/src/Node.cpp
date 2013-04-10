#include "cinder/gl/gl.h"
#include "Node.h"

Node::Node(ci::Vec2f pos) : VerletParticle(pos) {
}

void Node::draw() {
  ci::gl::color(0.8, 0.8, 0.8, 1);
  ci::gl::drawSolidCircle( position, 16 );
}
