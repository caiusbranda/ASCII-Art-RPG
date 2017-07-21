#ifndef __BAPOTION_H__
#define __BAPOTION_H__
#include "potion.h"

class BAPotion final : public Potion{
	public:
	  BAPotion();
		void use(Player &p) override;
};

#endif
