#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"
#include "player.h"


class Shade;
class Subject;

class Enemy : public Character, public Observer {
	bool nearPlayer;

public:

	Enemy(int maxhp, int hp, int att, int def, Posn p, char icon);

	SubscriptionType getSubType() const override;

	void notify(Subject *whoNotified) override;

	char getType() const override;

  bool isNearPlayer() const;

	virtual ~Enemy() = default;

  virtual int attack(Player *player) = 0;

  virtual int attackedBy(Shade *e);

  /*

  virtual int attackedBy(Drow *e);

  virtual int attackedBy(Goblin *e);

  virtual int attackedBy(Vampire *e);

  virtual int attackedBy(Troll *e);
  */

};

#include "elf.h"
#endif
