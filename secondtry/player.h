#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"

class Potion;

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

  virtual void attackedBy(Elf &e);

  virtual void attackedBy(Orc &e);
  
  virtual void attackedBy(Halfling &e);

  virtual void attackedBy(Dragon &e);

  virtual void attackedBy(Merchant &e);

  virtual void attackedBy(Dwarf &e);

  virtual void attackedBy(Human &e);
  
  virtual int potMag();

  bool move(const std::string &dir) override;

  Posn use(const std::string &dir);

  Stats getStats() const override;

  void setAction(const std::string &s) override;

  virtual void attack(Enemy *enemy) = 0;
};

#endif
