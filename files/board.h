#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <iostream>
#include <map>
#include "entity.h"

struct Posn {
	unsigned int x, y;

	Posn operator<(const Posn &rhs) const;
};


class Board {
	Map<Posn, Entity*> ents;



};

#endif
