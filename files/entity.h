#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "posn.h"

class Player;

// Entity is an abstract class
class Entity : public Subject {
	int x, y;
	char icon;
public:
  Posn getPosn() const;
  //virtual void use(Player &p);
  virtual ~Entity() = 0;
};

#endif
