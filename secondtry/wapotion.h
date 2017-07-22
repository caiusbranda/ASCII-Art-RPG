#ifndef __WAPOTION_H__
#define __WAPOTION_H__
#include "potion.h"

class WAPotion final : public Potion{
	public:
	  WAPotion();
		void use(Player &p) override;
};

#endif
