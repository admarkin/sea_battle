#ifndef SEABATTLE_BATTLE_H
#define SEABATTLE_BATTLE_H

#include "person.h"
#include "ship_4.h"
#include "factory.h"

class Battle {
private:
  Person first;
  Fleet fst;
  Person second;
  Fleet snd;
  class Factory;
  void Registration(Person&, Fleet&);
  void ShipPlacement(Person& person, Fleet& fleet, std::shared_ptr<IShip> ship, int count, int size);

public:
  explicit Battle() = default;
  void Start();
  void Game(Person&, Person&, Fleet&, Fleet&);
};

#endif