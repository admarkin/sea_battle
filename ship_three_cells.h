#ifndef SEABATTLE_SHIP_THREE_CELLS_H
#define SEABATTLE_SHIP_THREE_CELLS_H

#include <vector>
#include "iship.h"

class ShipThreeCells : public IShip {
public:
  int count_ = 2;
  int size_ = 3;
  Cell first;
  Cell second;
  Cell third;
  std::vector<Cell> v;

  ShipThreeCells() = default;
  bool Dead() const override {
    return first.dead && second.dead && third.dead;
  }
  bool Search(char str, int yy) override {
    if (str == first.x && yy == first.y) {
      first.dead = true;
      return true;
    }
    if (str == second.x && yy == second.y) {
      second.dead = true;
      return true;
    }
    if (str == third.x && yy == third.y) {
      third.dead = true;
      return true;
    }
    return false;
  }
};

#endif
