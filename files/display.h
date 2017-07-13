#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <iostream>
#include <map>
#include "observer.h"
#include "posn.h"

struct Posn;

class Display final : public Observer {
	std::map<Posn, char> theDisplay;

	const int h; // height will be 25
	const int w; // width 79

public:

	Display();
	~Display();

	// updates theDisplay at Posn of who notified
	//void notify(Subject &whoNotified);

	SubscriptionType getSubType() const override;

	// to output
	friend std::ostream &operator<<(std::ostream &out, const Display &d);
};

#endif
