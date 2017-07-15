#ifndef _POTION_H
#define _POTION_H
#include "item.h"

class Potion : public Item{
	// insert inherited fields from Item
	public:
		Potion();
		~Potion();
		void use(Player &p);
};
