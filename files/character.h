#ifndef __CHARACTERS_H__
#define __CHARACTERS_H__

#include "entity.h"
#include "posn.h"


class Character : public Entity {

	const int maxhp;

	int hp;
	int att;
	int def;

	Posn p;

public:

	Character(int maxhp, int hp, int att, int def, Posn p);

// accessors:
	int getMaxHp() const;
	int getHp() const;
	int getAtt() const;
	int getDef() const;

  //virtual void move(string dir);

  virtual void attack(Character &other) = 0;

};

#endif
