#ifndef SEABATTLE_FLOT_H
#define SEABATTLE_FLOT_H

#include <vector>
#include <memory>
#include "iship.h"
#include "ship_four_cells.h"
#include "ship_three_cells.h"
#include "ship_two_cells.h"
#include "ship_one_cell.h"
#include "factory.h"

class Fleet {
public:
  Factory factory;
  std::vector<std::shared_ptr<IShip>> ships;
};

#endif
