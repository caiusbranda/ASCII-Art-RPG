#include "display.h"

using namespace std;

Display::Display() :  theDisplay{}, h{25}, w{79} {
	// each row
	for (int y = 0; y < h; ++y) {
		// each column
		for (int x = 0; x < w; ++x) {
			Posn p{x,y};

			// left/right border
			if (p.x == 0 || p.x == w-1) {

				theDisplay[p] = '|';
			}
				// top/bottom border
			else if (p.y == 0 || p.y == h-1) theDisplay[p] = '-';

				// empty space
			else {
				theDisplay[p] = ' ';
			}
		}
	}
}

Display::~Display() {}

SubscriptionType Display::getSubType() const {
	return SubscriptionType::Display;
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
