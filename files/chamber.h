#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <map>

#include "room.h"
#include "posn.h"
#include "tile.h"

struct Posn;

class Chamber final : public Room {
	Posn p;
	int type; // which chamber is it?
	std::map<Posn,Tile*> tiles; // map of tile pointers with Posn as key

public:

	Posn getPosn() const override;

	Chamber(int type); // so it knows which chamber is being constructed
	~Chamber(); // Dtor also deletes tiles

};

#endif
