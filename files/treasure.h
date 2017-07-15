#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"

class Treasure final : public Item {
	int value;

public:

	void use(Player &p) override;

};

#endif
