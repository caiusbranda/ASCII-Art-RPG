#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"

class Enemy : public Character {


	bool hostile;


public:

	virtual Enemy();
	virtual ~Enemy();
  virtual void attackedBy(Shade &e) = 0;
  virtual void attackedBy(Drow &e) = 0;
  virtual void attackedBy(Goblin &e) = 0;
  virtual void attackedBy(Vampire &e) = 0;
  virtual void attackedBy(Troll &e) = 0;

};

#endif
