#ifndef SEABATTLE_FACTORY_H
#define SEABATTLE_FACTORY_H

#include "ship_one_cell.h"
#include "ship_two_cells.h"
#include "ship_three_cells.h"
#include "ship_four_cells.h"

class Factory {
  ShipOneCell& GetShipOneCell();
  ShipTwoCells& GetShipTwoCells();
  ShipThreeCells& GetShipThreeCells();
  ShipFourCells& GetShipFourCells();
};

#endif