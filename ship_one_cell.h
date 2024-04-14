#ifndef SEABATTLE_SHIP_ONE_CELL_H
#define SEABATTLE_SHIP_ONE_CELL_H

#include <cstdint>
#include <vector>
#include "iship.h"

class ShipOneCell : public IShip {
public:
  int count_ = 4;
  int size_ = 1;
  Cell first;
  std::vector<Cell> v;
  ShipOneCell() = default;
  bool Dead() const override {
    return first.dead;
  }
  bool Search(char str, int yy) override {
    if (str == first.x && yy == first.y) {
      first.dead = true;
      return true;
    }
    return false;
  }
};


#endif

