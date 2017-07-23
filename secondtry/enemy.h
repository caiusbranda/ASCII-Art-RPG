#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"

class Enemy : public Character, public Observer {
	bool nearPlayer;

public:

	Enemy(int maxhp, int hp, int att, int def, Posn p, char icon);

	SubscriptionType getSubType() const override;

	void notify(Subject *whoNotified) override;

	char getType() const override;

  bool isNearPlayer() const;

	virtual ~Enemy() = 0;

  virtual void attack(Player *player) = 0;

  virtual void attackedBy(Shade *e);

  virtual void attackedBy(Drow *e);

  virtual void attackedBy(Goblin *e);

  virtual void attackedBy(Vampire *e);

  virtual void attackedBy(Troll *e);

};

#endif
