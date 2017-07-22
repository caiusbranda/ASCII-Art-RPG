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

	/*
	void notifyComing(Subject *whoNotified) override;
	void notifyLeave() override;
	*/
	char getType() const override;
	void notify(Subject *whoNotified) override;
	SubscriptionType getSubType() const override;

	virtual void use(Player &p) = 0;
};

#endif
