#ifndef SEABATTLE_SHIP_1_H
#define SEABATTLE_SHIP_1_H

#include <cstdint>
#include <vector>
#include "iship.h"

class ShipOne : public IShip {
public:
  int count_ = 4;
  int size_ = 1;
  Boat boat;
  std::vector<Boat> v;
  ShipOne() = default;
  bool Dead() const override {
    return boat.dead;
  }
  bool Search(char str, int yy) override {
    if (str == boat.x && yy == boat.y) {
      boat.dead = true;
      return true;
    }
    return false;
  }
};


#endif

