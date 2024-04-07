#ifndef SEABATTLE_BATTLE_H
#define SEABATTLE_BATTLE_H

#include "person.h"
#include "ship_four_cells.h"
#include "factory.h"

class Battle {
private:
  Person first;
  Fleet fst;
  Person second;
  Fleet snd;
  Battle() = default;
  void Registration(Person&, Fleet&);
  void ShipPlacement(Person& person, Fleet& fleet, std::shared_ptr<IShip> ship, int count, int size);
  void Game(Person&, Person&, Fleet&, Fleet&);

public:
  void Start();
  static Battle* getInstance() {
    static Battle instance;
    return &instance;
  }
};

#endif