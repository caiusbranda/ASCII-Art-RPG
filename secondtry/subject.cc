#include "subject.h"

void Subject::attach(const Posn &p, Observer *o) {
	this->tileObservers[p] = o;
}

void Subject::attach(Observer *o) {
	this->otherObservers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
	for (auto &i : tileObservers) {
		if (t == i.second->getSubType()) i.second->notify(this);
	}

	for (auto &i : otherObservers) {
		if (t == i->getSubType()) i->notify(this);
	}

}

/*
void Subject::notifyDisplay() {
	this->display->notifyComing(this);
}
*/


Subject::~Subject(){}
