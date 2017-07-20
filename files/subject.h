#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>
#include "posn.h"
#include "display.h"
#include "subscriptions.h"

struct Posn;
class Observer;
class Display;

class Subject {
	Display *display;

public:
	void attach(Display *o);
	void notifyDisplay();
	virtual ~Subject() = 0;
};

#endif
