#include "display.h"

using namespace std;

Display::Display()
: theDisplay{}, h{25}, w{79}, race{""}, gold{0}, floor{0}, hp{0}, att{0},
	def{0}, action{""} {}

Display::~Display() {}

SubscriptionType Display::getSubType() const {
	return SubscriptionType::Display;
}

void Display::updateDisplay(const Posn &p, char c) {
	theDisplay[p] = c;
}

void Display::notify(Subject *whoNotified) {
	doNotify(whoNotified);
}

void Display::notify(Player *whoNotified) {
	doNotify(whoNotified);
	this->gold = whoNotified->getGold();
	this->race = whoNotified->getRace();
	this->hp = whoNotified->getHp();
	this->att = whoNotified->getAtt();
	this->def = whoNotified->getDef();
	this->action = whoNotified->getAction();
}

void Display::doNotify(Subject *whoNotified) {
	Posn curPos = whoNotified->getCurPos();
	Posn lastPos = whoNotified->getLastPos();
	char c = whoNotified->getIcon();
	updateDisplay(curPos, c);
}

char Display::getType() const {
	return 0;
}

std::ostream &operator<<(std::ostream &out, const Display &d) {

	for (int y = 0; y < d.h; ++y) {
		for (int x = 0; x < d.w; ++x) {
			Posn p{x,y};
			out << d.theDisplay.at(p);
		}
		out << endl;
	}

	out << "Race: " << d.race;
	out << " Gold: " << d.gold << endl;
	out << "HP: " << d.hp << endl;
	out << "Atk: " << d.att << endl;
	out << "Def: " << d.def << endl;
	out << "Action: " << d.action << endl;

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
