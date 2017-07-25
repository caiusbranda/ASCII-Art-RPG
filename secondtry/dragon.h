#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"

class Player;

class Dragon final : public Enemy {

public:
  Dragon(Posn p);
  ~Dragon();

  int attack(Player *player) override;

  std::string getRace() const override;
};

#endif
