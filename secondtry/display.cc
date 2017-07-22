#include "display.h"

using namespace std;

Display::Display() : theDisplay{}, h{25}, w{79} {}

Display::~Display() {}

SubscriptionType Display::getSubType() const {
	return SubscriptionType::Display;
}

void Display::updateDisplay(const Posn &p, char c) {
	theDisplay[p] = c;
}

void Display::notify(Subject *whoNotified) {
	Posn curPos = whoNotified->getCurPos();
	Posn lastPos = whoNotified->getLastPos();
	char c = whoNotified->getIcon();

	updateDisplay(lastPos, '.');
	updateDisplay(curPos, c);

}

std::ostream &operator<<(std::ostream &out, const Display &d) {

	for (int y = 0; y < d.h; ++y) {
		for (int x = 0; x < d.w; ++x) {
			Posn p{x,y};
			out << d.theDisplay.at(p);
		}
		out << endl;
	}
	return out;
}

/*
void Display::notifyComing(Subject *whoNotified) {
	this->theDisplay[whoNotified->getPosn()] = whoNotified->getType();
}

void Display::notifyLeave() {
	return;
}
*/
void Display::getHW(int &height, int &width) {
	height = h;
	width = w;
}
