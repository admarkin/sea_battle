#include <memory>
#include "../include/factory.h"
#include "../include/boat.h"


std::shared_ptr<Boat> Factory::GetShipOneCell() {
  return std::make_shared<Boat>(Boat());
}

std::shared_ptr<Catamaran> Factory::GetShipTwoCells() {
  return std::make_shared<Catamaran>(Catamaran());
}

std::shared_ptr<Barge> Factory::GetShipThreeCells() {
  return std::make_shared<Barge>(Barge());
}

std::shared_ptr<Cruiser> Factory::GetShipFourCells() {
  return std::make_shared<Cruiser>(Cruiser());
}