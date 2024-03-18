#ifndef SEABATTLE_SHIP_3_H
#define SEABATTLE_SHIP_3_H

#include <vector>
#include "iship.h"

class ShipThree : public IShip {
public:
  int count_ = 2;
  int size_ = 3;
  Boat first;
  Boat second;
  Boat third;
  std::vector<Boat> v;

  ShipThree() = default;
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
