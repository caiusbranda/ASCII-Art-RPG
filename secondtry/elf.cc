#include "elf.h"
using namespace std;


  Elf::Elf(Posn p) : Enemy{110, 110, 15, 20, p, 'E'} {}

  Elf::~Elf() {}

void Elf::notify(Subject *whoNotified) {
  this->attack(whoNotified);

  // has attacked
  this->hasAttacked = true;
}
