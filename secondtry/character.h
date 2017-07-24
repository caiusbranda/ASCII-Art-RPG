#ifndef __CHARACTERS_H__
#define __CHARACTERS_H__

#include "entity.h"
#include "posn.h"
#include "tile.h"
#include <cmath>

class Character : public Entity {

	const int maxhp;

	int hp;
	int att;
	int def;

protected:

	virtual void moveEffect();
	virtual bool canMove(const Posn &np);

	void detachTiles();

public:

	Character(int maxhp, int hp, int att, int def, Posn p, char icon);

	// accessors:
	int getMaxHp() const;

	int getHp() const;

	int getAtt() const;

	int getDef() const;

  virtual bool move(const std::string &dir);

  virtual void attack(Character &other) = 0;

  virtual int calculateDamage(Character *attacker);

	// mutators:
	void setHp(int newHp);

  void setAtt(int newAtt);

  void setDef(int newDef);


};

#endif
