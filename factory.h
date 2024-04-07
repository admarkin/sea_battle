#ifndef SEABATTLE_FACTORY_H
#define SEABATTLE_FACTORY_H

#include "ship_one_cell.h"
#include "ship_two_cells.h"
#include "ship_three_cells.h"
#include "ship_four_cells.h"

class Factory {
public:
  std::shared_ptr<ShipOneCell> GetShipOneCell();
  std::shared_ptr<ShipTwoCells> GetShipTwoCells();
  std::shared_ptr<ShipThreeCells> GetShipThreeCells();
  static std::shared_ptr<ShipFourCells> GetShipFourCells();
};

#endif