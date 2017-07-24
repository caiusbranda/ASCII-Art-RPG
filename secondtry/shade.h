#ifndef __SHADE_H__
#define __SHADE_H__

#include "player.h"

class Enemy;
class Elf;

class Shade final : public Player {

public:

	Shade(Posn p);

  int attack(Enemy *enemy) override;

  int attackedBy(Elf *e) override;

  ~Shade();
};



#endif
