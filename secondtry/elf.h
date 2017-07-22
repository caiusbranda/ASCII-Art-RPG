#ifndef __ELF_H__
#define __ELF_H__

#include "enemy.h"

class Elf final : public Enemy {

public:
  Elf(Posn p);
  ~Elf();
};

#endif
