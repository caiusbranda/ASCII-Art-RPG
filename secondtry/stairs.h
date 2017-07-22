#ifndef __STAIRS_H__
#define __STAIRS_H__

#include "entity.h"
#include "observer.h"

class Stairs final : public Entity, public Observer {

public:
	Stairs(Posn p);
	~Stairs();

	void notify(Subject *whoNotified) override;

	SubscriptionType getSubType() const override;
};


#endif
