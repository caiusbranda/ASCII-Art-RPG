#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include <iostream>
#include <map>

#include "posn.h"

#include "observer.h"
#include "subject.h"
#include "display.h"

#include "room.h"
#include "chamber.h"
#include "passage.h"
#include "tile.h"

#include "entity.h"

class Board {

	std::map<Posn, Entity*> ents;

	int curFloor;

public:

	void initEmpty();

	int getCurFloor() const;


};

#endif
