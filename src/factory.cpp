#include <memory>
#include "../factory.h"
#include "../ship_one_cell.h"


std::shared_ptr<ShipOneCell> Factory::GetShipOneCell() {
  return std::make_shared<ShipOneCell>(ShipOneCell());
}

std::shared_ptr<ShipTwoCells> Factory::GetShipTwoCells() {
  return std::make_shared<ShipTwoCells>(ShipTwoCells());
}

std::shared_ptr<ShipThreeCells> Factory::GetShipThreeCells() {
  return std::make_shared<ShipThreeCells>(ShipThreeCells());
}

std::shared_ptr<ShipFourCells> Factory::GetShipFourCells() {
  return std::make_shared<ShipFourCells>(ShipFourCells());
}