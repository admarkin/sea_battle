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
