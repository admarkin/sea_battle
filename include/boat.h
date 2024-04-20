#ifndef SEABATTLE_SHIP_ONE_CELL_H
#define SEABATTLE_SHIP_ONE_CELL_H

#include <vector>
#include "iship.h"

class Boat : public IShip {
public:
  int count_ = 4;
  int size_ = 1;
  Cell first;
  Boat() = default;
  bool isDead() const override;
  bool Search(char str, int yy) override;
};

#endif