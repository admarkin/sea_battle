#ifndef SEABATTLE_SHIP_THREE_CELLS_H
#define SEABATTLE_SHIP_THREE_CELLS_H

#include <vector>
#include "iship.h"

class Barge : public IShip {
public:
  int count_ = 2;
  int size_ = 3;
  Cell first;
  Cell second;
  Cell third;

  Barge() = default;
  bool isDead() const override;
  bool Search(char str, int yy) override;
};

#endif
