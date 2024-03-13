#ifndef SEABATTLE_FLOT_H
#define SEABATTLE_FLOT_H

#include <vector>
#include <memory>
#include "iship.h"
#include "ship_4.h"
#include "ship_3.h"
#include "ship_2.h"
#include "ship_1.h"

class Flot {
public:
  std::vector<std::shared_ptr<IShip>> ships;
  std::shared_ptr<Ship_4> ship4;
  std::shared_ptr<Ship_3> ship3;
  std::shared_ptr<Ship_2> ship2;
  std::shared_ptr<Ship_1> ship1;
};

#endif
