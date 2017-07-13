#ifndef __TILE_H__
#define __TILE_H__

#include "posn.h"

struct Posn;

class Tile final : public Subject {
	Posn p;
	string type; // what kind of tile is it
	char disp;

public:

	// constructs a type of tile
	Tile(string type, Posn p);

	string getIcon() const override;



}

#endif
