#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"

class Treasure : public Item {

public:
	Treasure(Posn p, int amount, std::string type);
	void use(Subject &p) override;

	SubscriptionType getSubType() const override;

	virtual bool canPickUp();
	void pickAction(Subject &p);
	void notify(Subject *whoNotified) override;
};

#endif
