#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"
#include "enemy.h"

class Potion;
class Shade;
class Enemy;
class Elf;
class Player : public Character {

  std::string race;
  std::string action;
  int gold;


  Posn findDir(const std::string &dir);

  bool canUse(const Posn &np);

  bool canMove(const Posn &np) override;

public:

  Player(int maxhp, int hp, int att, int def, Posn p, std::string race);

  virtual ~Player() = default;

  char getIcon() const override;

  virtual int attackedBy(Elf *e);

  /*
  virtual int attackedBy(Orc *e);

  virtual int attackedBy(Halfling *e);

  virtual int attackedBy(Dragon *e);

  virtual int attackedBy(Merchant *e);

  virtual int attackedBy(Dwarf *e);

  virtual int attackedBy(Human *e);
  */

  virtual int potMag();

  bool move(const std::string &dir);

  Posn use(const std::string &dir);

  Stats getStats() const override;

  void setAction(const std::string &s) override;

  void appendAction(const std::string &s);

  Posn canAttack(const std::string &dir, std::map<Posn, Enemy*> &enemies);

  virtual int attack(Enemy *enemy) = 0;

  std::string getRace() const override;

	int getGold();

	void setGold(int newGold);
};
#include "shade.h"
#endif
