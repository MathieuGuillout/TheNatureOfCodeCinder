#ifndef MCL_H
#define MCL_H

#include <Box2D/Box2D.h>
#include "Box.h"

class MyContactListener : public b2ContactListener
{
  public:
    void BeginContact(b2Contact * contact) {
      //ci::app::console() << "CONTACT" << std::endl;
      
      const b2Body* bodyA = contact->GetFixtureA()->GetBody();
      const b2Body* bodyB = contact->GetFixtureB()->GetBody();

      Box * box1 = (Box *) bodyA->GetUserData();
      Box * box2 = (Box *) bodyB->GetUserData();

      box1->change();
      box2->change();
    }
};
#endif
