#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "subscriptions.h"
class Subject;

class Observer {
public:
	virtual void notifyComing(Tile &whoNotified) = 0;
	virtual void notifyLeave() = 0 ;
	virtual SubscriptionType getSubType() const = 0;
	virtual ~Observer() = default;

	virtual notifyDisplayComing();
};

#endif
