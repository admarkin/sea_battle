#ifndef SEABATTLE_PERSON_H
#define SEABATTLE_PERSON_H

#include <string>
#include <vector>
#include <memory>
#include "iship.h"
#include "flot.h"

class Person {
public:
  std::string name;
  std::string password;
  Flot flot;
  Person() = default;
};

#endif
