#ifndef SEABATTLE_SHIP_TWO_CELLS_H
#define SEABATTLE_SHIP_TWO_CELLS_H

#include <vector>
#include "iship.h"

class Catamaran : public IShip {
public:
  int count_ = 3;
  int size_ = 2;
  Cell first;
  Cell second;
  Catamaran() = default;
  bool isDead() const override;
  bool Search(char str, int yy) override;
};

#endif
