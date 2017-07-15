#ifndef __POTION_H__
#define __POTION_H__

#include <string>
#include "item.h"

class Potion final : public Item {

	int amount;
	std::string type;

public:

	void use(Player &p) override;

};

#endif
