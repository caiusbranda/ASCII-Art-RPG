#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>
#include <map>

#include "posn.h"
#include "display.h"
#include "subscriptions.h"

struct Posn;
class Observer;
class Display;

class Subject {

protected:
	std::vector<Observer *> otherObservers;
	std::map<Posn, Observer *> tileObservers;

public:
	void attach(const Posn &p, Observer *o);
	void attach(Observer *o);

	void notifyObservers(SubscriptionType t);

  virtual Posn getCurPos() const = 0;
  virtual Posn getLastPos() const = 0;
  virtual char getIcon() const = 0;
	virtual ~Subject() = 0;

};

#endif
