#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "posn.h"
#include "subject.h"


// Entity is an abstract class
class Entity : public Subject {
	Posn curPos;
	Posn lastPos;
	char icon;
public:

	Entity(Posn p, char icon);

	char getIcon() const override;

  Posn getCurPos() const override;
  Posn getLastPos() const override;
  //virtual void use(Player &p);
  virtual ~Entity() = 0;
};

#endif
