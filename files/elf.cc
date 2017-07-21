#include "elf.h"
using namespace std;


  Elf::Elf(Posn p) : Enemy{110, 110, 15, 20, p, true} {}
  

  //this means that the player called notifyComing on Elf. 
  // this tells Elf that player is now beside it.
  // 
  void Elf::notifyComing(Subject *whoNotified) {
    this->besidePlayer = true;
  }
  
  //idk if we have a use for this yet. we'll see
  void Elf::notifyLeave() {
  }
  
  SubscriptionType getSubType() {
    return SubscriptionType::Enemy;
  }
  
  Elf::~Elf() {}

  