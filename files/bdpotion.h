#ifndef __BDPOTION_H__
#define __BDPOTION_H__
#include "potion.h"

class BDPotion final : public Potion{
	public:
	  BDPotion();
		void use(Player &p) override;
};

#endif
