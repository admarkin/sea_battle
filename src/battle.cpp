
#include <iostream>
#include "../include/battle.h"
#include "../include/cruiser.h"
#include "../include/boat.h"
#include "../include/catamaran.h"
#include "../include/barge.h"
#include "../include/factory.h"

void Battle::ShipPlacement(Person& person, Fleet& fleet, std::shared_ptr<IShip> ship, int count, int size) {
  for (int i = 0; i < count; ++i) {
    std::cout << "Введите координаты для " << size << " палубных кораблей буквы: abc..ij, цифры от 1 до 10" << std::endl;
    std::cout << size << " пары координат по 1 букве и 1 цифре" << std::endl;
    for (int i = 0; i < size; ++i) {
      char x = 0;
      int y = 0;
      std::cin >> x >> y;
      while (y > 10 || y < 1 || x > 'j' || x < 'a') {
        std::cout << "Неправильный ввод, попробуйте ещё раз" << std::endl;
        std::cin >> x >> y;
      }
      ship->cells.emplace_back(x, y);
    }
    std::cout << "Корабль установлен успешно" << std::endl;
    fleet.ships.push_back(ship);
  }
}

void Battle::Registration(Person& person, Fleet& fleet) {
  std::cout << "Здравствуйте, это игра Морской бой, пожалуйста, зарегестрируйтесь" << std::endl;
  std::cout << "Введите ваше имя или ник" << std::endl;
  std::cin >> person.name;
  std::cout << "Придумайте пароль для входа в систему" << std::endl;
  std::cin >> person.password;
  std::cout << "Регистрация завершена, приступите к расстановке кораблей" << std::endl;
  ShipPlacement(person, fleet, fleet.factory.GetShipFourCells(), 1, 4);
  //ShipPlacement(person, fleet, fleet.factory.GetShipThreeCells(), 2, 3);
  //ShipPlacement(person, fleet, fleet.factory.GetShipThreeCells(), 3, 2);
  //ShipPlacement(person, fleet, fleet.factory.GetShipOneCell(), 4, 1);
}

void Battle::Game(Person& person, Person& second, Fleet& fleet, Fleet& snd) {
  while (true) {
    std::cout << "Ход игрока " << person.name << ". Пожалуйста введите ваш пароль" << std::endl;
    std::string pass;
    std::cin >> pass;
    while (pass != person.password) {
      std::cout << "Неверный пароль, попробуйте ещё раз" << std::endl;
      std::cin >> pass;
    }
    std::cout << "Введите координаты цели, буквы: abc..ij, цифры от 1 до 10" << std::endl;
    char x;
    bool shot = false;
    int y;
    std::cin >> x >> y;
    while (y > 10 || y < 1 || x > 'j' || x < 'a') {
      std::cout << "Неправильный ввод, попробуйте ещё раз" << std::endl;
      std::cin >> x >> y;
    }
    for (int i = 0; i < fleet.ships.size(); ++i) {
      shot = fleet.ships[i]->Search(x, y);
      if (shot) {
        std::cout << "Попал" << std::endl;
        if (fleet.ships[i]->isDead()) {
          std::cout << "Корабль убит" << std::endl;
        }
        break;
      }
    }
    if (fleet.isAllShipsDead()) {
      std::cout << "Все вражеские корабли уничтожены" << std::endl;
      std::cout << "Ура! Победа игрока: " << person.name << ". Поздравляем" << std::endl << "Игра окончена" << std::endl;
      break;
    }
    if (!shot) {
      std::cout << "Мимо" << std::endl;
    }
    if (shot) {
      continue;
    }
    std::swap(second, person);
    std::swap(snd, fleet);
  }
}

void Battle::Start() {
  Registration(first, fst);
  Registration(second, snd);
  Game(first, second, snd, fst);
}

Battle * Battle::getInstance() {
  static Battle instance;
  return &instance;
}