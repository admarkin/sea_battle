#ifndef SEABATTLE_BATTLE_H
#define SEABATTLE_BATTLE_H

#include "person.h"
#include "cruiser.h"
#include "factory.h"
#include "field.h"

class Battle {
private:
  Person first;
  Fleet fst;
  Person second;
  Fleet snd;
  Battle() = default;
  void Registration(Person&, Fleet&);
  void ShipPlacement(Person& person, Fleet& fleet, std::shared_ptr<IShip> ship, int count, int size, Field& field);
  void Game(Person&, Person&, Fleet&, Fleet&);

public:
  void Start();
  static Battle* getInstance();
};

#endif