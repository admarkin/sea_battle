#ifndef SEABATTLE_FLOT_H
#define SEABATTLE_FLOT_H

#include <vector>
#include <memory>
#include "iship.h"
#include "ship_four_cells.h"
#include "ship_three_cells.h"
#include "ship_two_cells.h"
#include "ship_one_cell.h"

class Fleet {
  class Factory;
public:
  std::vector<std::shared_ptr<IShip>> ships;
  std::shared_ptr<ShipFourCells> ship4;
  std::shared_ptr<ShipThreeCells> ship3;
  std::shared_ptr<ShipTwoCells> ship2;
  std::shared_ptr<ShipOneCell> ship1;
};

#endif
