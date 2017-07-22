#ifndef __WDPOTION_H__
#define __WDPOTION_H__
#include "potion.h"

class WDPotion final : public Potion{
	public:
	  WDPotion();
		void use(Player &p) override;
};

#endif
