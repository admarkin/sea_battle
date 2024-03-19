#ifndef SEABATTLE_ISHIP_H
#define SEABATTLE_ISHIP_H

#include <cstdint>
#include <vector>

struct Cell {
  char x = 0;
  int y = 0;
  bool dead = false;
  Cell() = default;
  Cell(char xx, int yy) : x(xx), y(yy), dead(false){};
};

class IShip {
public:
  int count_ = 0;
  int size_ = 0;
  Cell boat;
  std::vector<Cell> v;
  virtual bool Dead() const = 0;
  virtual bool Search(char, int) = 0;
};

#endif