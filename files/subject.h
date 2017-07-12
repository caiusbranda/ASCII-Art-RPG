#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>
#include "posn.h"
#include "subcriptions.h"

struct Posn;
class Observer;

class Subject {
  std::vector<Observer*> observers;

 public:
  void attach(Observer *o);
  void notifyObservers(SubscriptionType t);
  virtual string getType() const = 0;
  virtual ~Subject() = 0;
};

#endif
