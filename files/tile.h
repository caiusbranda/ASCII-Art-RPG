#ifndef __TILE_H__
#define __TILE_H__

#include "posn.h"

struct Posn;

class Tile final : public subject {
	Posn p;
	string type; // what kind of tile is it

public:
	string getState() const override;
}

#endif
