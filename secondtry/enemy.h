#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"

class Enemy : public Character, public Observer {

public:

	Enemy(int maxhp, int hp, int att, int def, Posn p, char icon);

	SubscriptionType getSubType() const override;

	void notify(Subject *whoNotified) override;

	char getType() const override;

	virtual ~Enemy() = 0;

	/*
  virtual void attackedBy(Shade &e) = 0;
  virtual void attackedBy(Drow &e) = 0;
  virtual void attackedBy(Goblin &e) = 0;
  virtual void attackedBy(Vampire &e) = 0;
  virtual void attackedBy(Troll &e) = 0;
	*/
};

#endif
