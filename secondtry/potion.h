#ifndef __POTION_H__
#define __POTION_H__

#include "item.h"

class Potion : public Item {
	bool isNearby;

public:

	Potion(int amount, std::string type, bool isNearby);
	void use(Player &p) override;

};

#endif
