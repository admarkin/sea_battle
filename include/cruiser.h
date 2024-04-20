#ifndef SEABATTLE_SHIP_FOUR_CELLS_H
#define SEABATTLE_SHIP_FOUR_CELLS_H

#include <vector>
#include "iship.h"

class Cruiser : public IShip {
public:
  int count_ = 1;
  int size_ = 4;
  Cell first;
  Cell second;
  Cell third;
  Cell fourth;

public:
  Cruiser() = default;
  bool isDead() const override;
  bool Search(char str, int yy) override;
};


#endif
