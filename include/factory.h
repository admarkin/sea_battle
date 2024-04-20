#ifndef SEABATTLE_FACTORY_H
#define SEABATTLE_FACTORY_H

#include "boat.h"
#include "catamaran.h"
#include "barge.h"
#include "cruiser.h"

class Factory {
public:
  std::shared_ptr<Boat> GetShipOneCell();
  std::shared_ptr<Catamaran> GetShipTwoCells();
  std::shared_ptr<Barge> GetShipThreeCells();
  std::shared_ptr<Cruiser> GetShipFourCells();
};

#endif