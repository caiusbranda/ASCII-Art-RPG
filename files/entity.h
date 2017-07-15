#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "posn.h"

// Entity is an abstract class
class Entity {
	int x, y;
	char icon;
public:
  Posn getPosn();
  virtual ~Entity() = 0;
}
#endif
