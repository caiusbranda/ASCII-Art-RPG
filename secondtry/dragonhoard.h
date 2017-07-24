#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__

#include "treasure.h"

class DragonHoard final : public Treasure{
	bool DragonSlain;
public:
	DragonHoard();
	bool canPickUp() override;
};

#endif
