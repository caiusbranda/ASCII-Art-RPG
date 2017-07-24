#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"

class Treasure : public Item {

public:
	Treasure(Posn p, int amount, std::string type);
	void use(Player &p);// override;
	virtual bool canPickUp();
	void pickAction(Player &p);
	void notify(Subject *whoNotified) override;
};

#endif
