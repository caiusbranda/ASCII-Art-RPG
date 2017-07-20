#include "subject.h"

void Subject::attach(Display *o) {
	this->display = o;
}

void Subject::notifyDisplay() {
	this->display->notifyComing(this);
}


Subject::~Subject(){}