#ifndef __RHPOTION_H__
#define __RHPOTION_H__
#include "potion.h"

class RHPotion final : public Potion{
	public:
	  RHPotion();
		void use(Player &p) override;
};

#endif
