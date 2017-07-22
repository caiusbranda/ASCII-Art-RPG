#include "item.h"
using namespace std;

// Ctor
Item::Item(int amount, string type): amount{amount}, type{type}{}

void Item::notify(Subject *whoNotified) {
	return;
}

// void Item::notifyComing(Subject *whoNotified){}

// void Item::notifyLeave(){}

SubscriptionType Item::getSubType() const {
	return SubscriptionType::Item;
}
