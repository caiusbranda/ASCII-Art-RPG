#ifndef __TILE_H__
#define __TILE_H__

#include "posn.h"

struct Posn;

class Tile final : public Subject, public Observer {
	Posn p;
	char type; // used for printing to display and determining its type

public:

	// constructs a type of tile
	Tile(string type, Posn p);

	char getType() const override;

  //notifies this tile that the thing previously on it has left (and thus revert to default)
  void notifyLeave() override;

  void notifyComing(Subject &whoNotified) override;
}

#endif
