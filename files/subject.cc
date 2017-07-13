#include "subject.h"

void Subject::attach(Observer *o) {
	observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
	return;
}

Subject::~Subject() {}
