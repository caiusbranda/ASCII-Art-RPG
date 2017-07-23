
#ifndef __POTION_H__
#define __POTION_H__

#include <iostream>

#include "item.h"
#include "player.h"

class Potion : public Item {

public:

	Potion(Posn p, int amount, std::string type);
	~Potion();

	void use(Player &p) override;

	SubscriptionType getSubType() const override;



};

#endif
