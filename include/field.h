#ifndef SEABATTLE_FIELD_H
#define SEABATTLE_FIELD_H

#include <vector>
#include <memory>
#include "iship.h"

class Field {
 public:
  std::vector<std::vector<int>> field;
  explicit Field() {
    field.resize(10, std::vector<int>(10, 0));
  }
  void PlaceShip(const std::shared_ptr<IShip>& ship);
  bool FindCoord(char x, int y);
};


#endif
