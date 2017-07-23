#ifndef __GOBLIN_H__
#define __GOBLIN_H__


#include <cstdlib>
#include <ctime>

#include "player.h"

class Goblin final : public Player {

public:
	Goblin(Posn p);

	~Goblin();

  void attack(Enemy *enemy) override;

};

#endif
