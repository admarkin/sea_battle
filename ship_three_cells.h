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
    int alive = 0;
    for (auto ship : v) {
      if (!ship.dead) {
        ++alive;
      }
    }
    if (alive) {
      return false;
    }
    return true;
  }
  bool Search(char str, int yy) override {
    bool search = false;
    for (auto &ship: v) {
      if (ship.x == str && ship.y == yy) {
        ship.dead = true;
        search = true;
      }
    }
    return search;
  }
};

#endif
