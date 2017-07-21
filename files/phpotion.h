#ifndef __PHPOTION_H__
#define __PHPOTION_H__
#include "potion.h"

class PHPotion final : public Potion{
	public:
	  PHPotion();
		void use(Player &p) override;
};

#endif
