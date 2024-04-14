#ifndef SEABATTLE_SHIP_TWO_CELLS_H
#define SEABATTLE_SHIP_TWO_CELLS_H

#include <vector>
#include "iship.h"

class ShipTwoCells : public IShip {
public:
  int count_ = 3;
  int size_ = 2;
  Cell first;
  Cell second;
  std::vector<Cell> v;
  ShipTwoCells() = default;
  bool Dead() const override {
    return first.dead && second.dead;
  }
  bool Search(char str, int yy) override {
    if (str == first.x && yy == first.y) {
      first.x = true;
      return true;
    }
    if (str == second.x && yy == second.y) {
      second.x = true;
    }
    return false;
  }
};

#endif
