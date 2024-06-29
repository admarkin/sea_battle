#include <gtest/gtest.h>
#include "../include/catamaran.h"
#include "../src/catamaran.cpp"
#include "../src/barge.cpp"
#include "../src/factory.cpp"
#include "../src/cruiser.cpp"
#include "../src/boat.cpp"
#include "../src/battle.cpp"
#include "../src/fleet.cpp"
#include "../src/field.cpp"
#include "cstring"
#include <string>

#include "../include/person.h"
#include "../include/factory.h"
#include "../include/barge.h"
#include "../include/battle.h"

TEST(SeaTest, BasicAssertions) {
  Factory factory;
  EXPECT_EQ(0, Cell().x);
  EXPECT_EQ(0, Cell().y);
  Cell cell;
  cell.x = 3;
  cell.y = 'z';
  EXPECT_EQ(3, cell.x);
  EXPECT_EQ('z', cell.y);
  auto catamaran = factory.GetCatamaran();
  catamaran->cells.push_back(cell);
  EXPECT_EQ(3, catamaran->cells.begin()->x);
  EXPECT_EQ('z', catamaran->cells.begin()->y);
  EXPECT_EQ(3, Cell('z', 3).y);
  EXPECT_EQ('z', Cell('z', 3).x);
}

template<typename T>
auto funk(T& obj) {
  auto arr = typeid(T).name();
  return arr;
}

TEST(FactoryTest, BasicAssertions) {
  Factory factory;
  std::string a = typeid(factory.GetCatamaran()).name();
  std::string b = typeid(std::shared_ptr<Catamaran>()).name();
  std::cout << a <<"     "<<  b;
  for (size_t i = 0; i < a.size() - 1; ++i) {
    EXPECT_EQ(a[i], b[i + 1]);
  }
  a = typeid(factory.GetBarge()).name();
  b = typeid(std::shared_ptr<Barge>()).name();
  std::cout << a <<"     "<<  b;
  for (size_t i = 0; i < a.size() - 1; ++i) {
    EXPECT_EQ(a[i], b[i + 1]);
  }
  a = typeid(factory.GetBoat()).name();
  b = typeid(std::shared_ptr<Boat>()).name();
  std::cout << a <<"     "<<  b;
  for (size_t i = 0; i < a.size() - 1; ++i) {
    EXPECT_EQ(a[i], b[i + 1]);
  }
  a = typeid(factory.GetCruiser()).name();
  b = typeid(std::shared_ptr<Cruiser>()).name();
  std::cout << a <<"     "<<  b;
  for (size_t i = 0; i < a.size() - 1; ++i) {
    EXPECT_EQ(a[i], b[i + 1]);
  }
  //EXPECT_EQ(factory.GetBarge(), std::shared_ptr<Barge>());
  //EXPECT_EQ(factory.GetCruiser(), std::shared_ptr<Cruiser>());
  //EXPECT_EQ(factory.GetBoat(), std::shared_ptr<Boat>());
}

TEST(PersonTest, BasicAssertions) {
  Person first;
  first.name = "cringe";
  EXPECT_EQ(first.name, "cringe");
  first.password = "1234";
  EXPECT_EQ(first.password, "1234");
  Person second(first);
  EXPECT_EQ(second.name, "cringe");
  EXPECT_EQ(second.password, "1234");
  auto third = second;
  EXPECT_EQ(third.name, "cringe");
  EXPECT_EQ(third.password, "1234");
}

TEST(EasyPlacement, Cringe) {
  Factory factory;
  auto cruis  = factory.GetCruiser();
  cruis->cells.emplace_back('a', 1);
  cruis->cells.emplace_back('b', 2);
  cruis->cells.emplace_back('c', 3);
  cruis->cells.emplace_back('d', 4);
  EXPECT_EQ(CorrectLinePlacement(cruis), false);
  cruis->cells.clear();
  cruis->cells.emplace_back('a', 1);
  cruis->cells.emplace_back('b', 1);
  cruis->cells.emplace_back('c', 1);
  cruis->cells.emplace_back('d', 1);
  EXPECT_EQ(CorrectLinePlacement(cruis), true);
  cruis->cells.clear();
  cruis->cells.emplace_back('a', 1);
  cruis->cells.emplace_back('b', 1);
  cruis->cells.emplace_back('d', 1);
  cruis->cells.emplace_back('e', 1);
  EXPECT_EQ(CorrectLinePlacement(cruis), false);
  cruis->cells.clear();
  cruis->cells.emplace_back('a', 5);
  cruis->cells.emplace_back('a', 6);
  cruis->cells.emplace_back('a', 7);
  cruis->cells.emplace_back('a', 8);
  EXPECT_EQ(CorrectLinePlacement(cruis), true);
}

TEST(FindEnemy, Cringe) {
  Fleet fleet;
  Factory factory;
  EXPECT_EQ(fleet.isAllShipsDead(), true);
  auto cruis  = factory.GetCruiser();
  cruis->cells.emplace_back('c', 5);
  cruis->cells.emplace_back('c', 6);
  cruis->cells.emplace_back('c', 7);
  cruis->cells.emplace_back('c', 8);
  fleet.ships.push_back(cruis);
  EXPECT_EQ(fleet.ships[0]->Search('c', 5), true);
  EXPECT_EQ(fleet.isAllShipsDead(), false);
  EXPECT_EQ(fleet.ships[0]->Search('c', 6), true);
  EXPECT_EQ(fleet.isAllShipsDead(), false);
  EXPECT_EQ(fleet.ships[0]->Search('c', 7), true);
  EXPECT_EQ(fleet.isAllShipsDead(), false);
  EXPECT_EQ(fleet.ships[0]->Search('c', 8), true);
  EXPECT_EQ(fleet.isAllShipsDead(), true);
  EXPECT_EQ(fleet.ships[0]->Search('a', 4), false);
  EXPECT_EQ(fleet.ships[0]->Search('c', 9), false);
  EXPECT_EQ(fleet.ships[0]->Search('f', 22), false);
  EXPECT_EQ(fleet.ships[0]->Search('4', 7), false);
  //мы сейчас подбили все корабли проверим что они все мертвы
  EXPECT_EQ(fleet.isAllShipsDead(), true);
}