#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "posn.h"
#include "subject.h"


// Entity is an abstract class
class Entity : public Subject {
	Posn p;
	char icon;
public:
  Posn getPosn() const override;
  //virtual void use(Player &p);
  virtual ~Entity() = 0;
};

#endif
