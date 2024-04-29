#ifndef SEABATTLE_FACTORY_H
#define SEABATTLE_FACTORY_H

#include "boat.h"
#include "catamaran.h"
#include "barge.h"
#include "cruiser.h"

class Factory {
public:
  std::shared_ptr<Boat> GetBoat();
  std::shared_ptr<Catamaran> GetCatamaran();
  std::shared_ptr<Barge> GetBarge();
  std::shared_ptr<Cruiser> GetCruiser();
};

#endif