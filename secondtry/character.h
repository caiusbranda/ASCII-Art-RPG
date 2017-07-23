#ifndef __CHARACTERS_H__
#define __CHARACTERS_H__

#include "entity.h"
#include "posn.h"
#include "tile.h"

class Character : public Entity {

	const int maxhp;

	int hp;
	int att;
	int def;

protected:
	virtual void moveEffect();
	bool canMove(const Posn &np);


public:

	Character(int maxhp, int hp, int att, int def, Posn p, char icon);

	// accessors:
	int getMaxHp() const;
	int getHp() const;
	int getAtt() const;
	int getDef() const;

  virtual bool move(const std::string &dir);

  //virtual void attack(Character &other) = 0;

	// mutators:
	void setHp(int newHp);
  void setAtt(int newAtt);
  void setDef(int newDef);

	//virtual void move(string dir);

	//virtual void attack(Subject *other);


};

#endif
