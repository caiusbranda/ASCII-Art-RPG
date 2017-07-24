#ifndef __SHADE_H__
#define __SHADE_H__

#include "player.h"

class Shade final : public Player {

public:

	Shade(Posn p);

  void attack(Enemy *enemy) const override;

  void attackedBy(Elf &e) const override;

  void attackedBy(Orc &e) const override;
  
  void attackedBy(Halfling &e) const override;

  void attackedBy(Dragon &e) const override;

  void attackedBy(Merchant &e) const override;

  void attackedBy(Dwarf &e) const override;

  void attackedBy(Human &e) const override;


  ~Shade();
};



#endif
