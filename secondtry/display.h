#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <iostream>
#include <map>
#include "observer.h"
#include "posn.h"
#include "subject.h"
#include "player.h"

class Subject;
struct Posn;

class Display final : public Observer {
	std::map<Posn, char> theDisplay;

	const int h; // height will be 25
	const int w; // width 79

	// for stats display
	std::string race;
	int gold;
	int floor;
	int hp;
	int att;
	int def;
	std::string action;


	void doNotify(Subject *whoNotified);

public:

	Display();
	~Display();

	void notify(Player *whoNotified);
	void notify(Subject *whoNotified) override;


	char getType() const override;

	void updateDisplay(const Posn &p, char c);

	// updates theDisplay at Posn of who notified
	//void notify(Subject &whoNotified);

/*
	void notifyComing(Subject *whoNotified) override;
	void notifyLeave() override;
*/

	SubscriptionType getSubType() const override;

	// puts h and w in height and width
	void getHW(int &height, int &width);

	// to output
	friend std::ostream &operator<<(std::ostream &out, const Display &d);
};

#endif
