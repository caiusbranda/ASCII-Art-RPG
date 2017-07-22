#include "subject.h"

void Subject::attach(Observer *o) {
	this->observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
	for (auto &i : observers) {
		if (t == i->getSubType()) i->notify(this);
	}
}

/*
void Subject::notifyDisplay() {
	this->display->notifyComing(this);
}
*/


Subject::~Subject(){}
