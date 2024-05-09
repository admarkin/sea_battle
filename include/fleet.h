#ifndef SEABATTLE_FLOT_H
#define SEABATTLE_FLOT_H

#include <vector>
#include <memory>
#include "iship.h"
#include "cruiser.h"
#include "barge.h"
#include "catamaran.h"
#include "boat.h"
#include "factory.h"

class Fleet {
public:
  Factory factory;
  std::vector<std::shared_ptr<IShip>> ships;
  bool isAllShipsDead();
};

#endif
