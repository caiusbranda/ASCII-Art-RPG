#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <std::vector<char> v;>

class Display final : public Observer {
	std::vector<std::vector<char>> theDisplay;

	const int h; // height
	const int w; // width

public:

	Display(int h, int w);
	// updates theDisplay at Posn of who notified
	virtual void notify(Subject &whoNotified);

	virtual SubscriptionType getSubType() override;

	// to output
	friend std::ostream &operator<<(std::ostream &out, const Display &d);
}

#endif
