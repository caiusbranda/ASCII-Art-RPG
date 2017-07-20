#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"

class Player : public Character {

public:

  virtual ~Player() = default;

  char getIcon() const;

  //virtual void move(string direction) = 0;

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
};

#endif