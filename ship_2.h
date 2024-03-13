#ifndef SEABATTLE_SHIP_2_H
#define SEABATTLE_SHIP_2_H

#include <vector>
#include "iship.h"

class Ship_2 : public IShip {
public:
  int count_ = 3;
  int size_ = 2;
  Boat first;
  Boat second;
  std::vector<Boat> v;
  Ship_2() = default;
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
