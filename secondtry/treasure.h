#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"

class Treasure : public Item {

public:
	Treasure(int amount);
	void use(Player &p) override;
	virtual bool canPickUp();
	void pickAction(Player &p);
};

#endif
