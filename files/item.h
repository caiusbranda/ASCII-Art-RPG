#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>
#include "Entity.h"

class Player;

class Item : public Entity, public Observer {
	int amount;
	std::string type;

public:
	Item(int amount);
	virtual ~Item() = 0;

	void notifyComing(Subject *whoNotified) override;
	void notifyLeave() override;
	SubscriptionType getSubType() override;

	virtual void use(Player &p) = 0; 
};

#endif
