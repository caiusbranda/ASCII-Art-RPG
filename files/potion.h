
#ifndef __POTION_H__
#define __POTION_H__

#include <string>
#include "item.h"

class Potion : public Item {
	std::string type;

public:

	Potion(int amount, std::string type);
	void use(Player &p) override;

};

#endif
