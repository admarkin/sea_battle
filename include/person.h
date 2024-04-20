#ifndef SEABATTLE_PERSON_H
#define SEABATTLE_PERSON_H

#include <string>
#include <vector>
#include <memory>
#include "iship.h"
#include "fleet.h"

class Person {
public:
  std::string name;
  std::string password;
  Person() = default;
};

#endif
