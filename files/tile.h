#ifndef __TILE_H__
#define __TILE_H__

#include "subject.h"
#include "observer.h"
#include "posn.h"

struct Posn;

class Tile final : public Subject, public Observer {
	Posn p;
	char type; // used for printing to display and determining its type
	int chamber; // which chamber is it in

public:

	// constructs a type of tile
	Tile(Posn p, char type);

  Posn getPosn() const;
  char getType() const;

  //notifies this tile that the thing previously on it has left (and thus revert to default)
  void notifyLeave() override;

  void notifyComing(Subject &whoNotified) override;

  SubscriptionType getSubType() const override;

  int getChamber() const;
  void setChamber(int cham);


};

#endif
