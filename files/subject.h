#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>
#include "posn.h"
#include "subscriptions.h"

struct Posn;
class Observer;

class Subject {
	std::vector<Observer*> observers;

public:
	void attach(Observer *o);
	void notifyObservers(SubscriptionType t);
	virtual char getType() const = 0;
	virtual ~Subject() = 0;
};

#endif
