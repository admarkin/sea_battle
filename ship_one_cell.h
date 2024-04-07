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