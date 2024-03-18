#ifndef SEABATTLE_SHIP_4_H
#define SEABATTLE_SHIP_4_H

#include <vector>
#include "iship.h"

class ShipFour : public IShip {
public:
  int count_ = 1;
  int size_ = 4;
  Boat first;
  Boat second;
  Boat third;
  Boat fourth;
  std::vector<Boat> v;

public:
  ShipFour() = default;
  bool Dead() const override {
    return first.dead && second.dead && third.dead && fourth.dead;
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
    if (str == fourth.x && yy == fourth.y) {
      fourth.dead = true;
      return true;
    }
    return false;
  }
};


#endif
