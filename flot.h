#ifndef SEABATTLE_FLOT_H
#define SEABATTLE_FLOT_H

#include <vector>
#include <memory>
#include "iship.h"
#include "ship_4.h"
#include "ship_3.h"
#include "ship_2.h"
#include "ship_1.h"

class Fleet {
  class Factory;
public:
  std::vector<std::shared_ptr<IShip>> ships;
  std::shared_ptr<ShipFour> ship4;
  std::shared_ptr<ShipThree> ship3;
  std::shared_ptr<ShipTwo> ship2;
  std::shared_ptr<ShipOne> ship1;
};

#endif
