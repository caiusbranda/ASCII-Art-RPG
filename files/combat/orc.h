#ifndef __ORC_H__
#define __ORC_H__

#include "enemy.h"

class Orc final : public Enemy {


public:

	void attackedBy(Goblin &g) = 0 override;

};

#endif
