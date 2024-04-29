#include <memory>
#include "../include/factory.h"
#include "../include/boat.h"


std::shared_ptr<Boat> Factory::GetBoat() {
  return std::make_shared<Boat>(Boat());
}

std::shared_ptr<Catamaran> Factory::GetCatamaran() {
  return std::make_shared<Catamaran>(Catamaran());
}

std::shared_ptr<Barge> Factory::GetBarge() {
  return std::make_shared<Barge>(Barge());
}

std::shared_ptr<Cruiser> Factory::GetCruiser() {
  return std::make_shared<Cruiser>(Cruiser());
}