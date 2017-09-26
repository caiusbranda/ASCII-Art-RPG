#ifndef __MERCHANT_H__
#define __MERCHANT_H__

#include "enemy.h"

class Player;

class Merchant final : public Enemy {

  static bool hostile;

public:
  Merchant(Posn p);

  ~Merchant();

  int attack(Player *player) override;

  bool isHostile() const override;

  int defaultAttack(Character *c) override;

  void checkEnemyDead(Player *killer) override;

  std::string getRace() const override;
};

#endif


