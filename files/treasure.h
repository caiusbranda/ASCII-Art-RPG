#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"

class Treasure final : public Item {

public:
	Treasure(int amount);
	void use(Player &p) override;

};

#endif
