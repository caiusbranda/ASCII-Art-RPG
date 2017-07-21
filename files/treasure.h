#ifndef __TREASURE_H__
#define __TREASURE_H__

#include "item.h"

class Treasure final : public Item {

public:
	Treasure(int amount, std::string type);
	void use(Player &p) override;

};

#endif
