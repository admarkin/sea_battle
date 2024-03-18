#ifndef SEABATTLE_FACTORY_H
#define SEABATTLE_FACTORY_H

#include "ship_1.h"
#include "ship_2.h"
#include "ship_3.h"
#include "ship_4.h"

class Factory {
  class ShipOne;
  class ShipTwo;
  class ShipThree;
  class ShipFour;
  Factory() = default;
  ShipOne& GetShipOne();
  ShipTwo& GetShipTwo();
  ShipThree& GetShipThree();
  ShipFour& GetShipFour();
};

#endif