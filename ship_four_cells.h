#ifndef SEABATTLE_SHIP_FOUR_CELLS_H
#define SEABATTLE_SHIP_FOUR_CELLS_H

#include <vector>
#include "iship.h"

class ShipFourCells : public IShip {
public:
  int count_ = 1;
  int size_ = 4;
  Cell first;
  Cell second;
  Cell third;
  Cell fourth;
  std::vector<Cell> v;

public:
  ShipFourCells() = default;
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
