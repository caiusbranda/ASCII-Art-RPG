#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"

class Player : public Character {

  std::string race;
  std::string action;
  int gold;

public:

  Player(int maxhp, int hp, int att, int def, Posn p, std::string race);

  virtual ~Player() = default;

  char getIcon() const override;

  //virtual void move(std::string direction);

  //virtual void attackedBy(Elf &e) = 0;
  //virtual void attackedBy(Orc &e) = 0;
  /*
  virtual void attackedBy(Halfling &e) = 0;
  virtual void attackedBy(Dragon &e) = 0;
  virtual void attackedBy(Merchant &e) = 0;
  virtual void attackedBy(Dwarf &e) = 0;
  virtual void attackedBy(Human &e) = 0;
  */

  virtual int potionMagnitude();

  bool move(const std::string &dir) override;

  Stats getStats() const override;

  virtual void attack(Enemy *enemy) = 0;

};

#endif
