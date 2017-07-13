#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include "subscriptions.h"

class Observer {
public:
	//virtual void notify(Subject &whoNotified) = 0;

	virtual SubscriptionType getSubType() const = 0;
	virtual ~Observer() = default;
};

#endif
