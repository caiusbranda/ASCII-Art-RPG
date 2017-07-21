#ifndef __ITEM_H__
#define __ITEM_H__

#include "Entity.h"

class Player;

class Item : public Entity {
	int amount;

public:
	Item(int amount);
	virtual ~Item() = 0;
	virtual void use(Player &p) = 0; 
};

#endif
