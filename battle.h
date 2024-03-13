#ifndef SEABATTLE_BATTLE_H
#define SEABATTLE_BATTLE_H

#include "person.h"
#include "ship_4.h"

class Battle {
private:
  Person first;
  Person second;
  void Registration(Person&);
  void ShipPlacement(Person& person, std::shared_ptr<IShip> ship, int count, int size);

public:
  explicit Battle() = default;
  void Start();
  void Game(Person&, Person&);
};

#endif