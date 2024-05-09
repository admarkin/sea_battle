#include <iostream>
#include <algorithm>
#include "../include/battle.h"
#include "../include/cruiser.h"
#include "../include/boat.h"
#include "../include/catamaran.h"
#include "../include/barge.h"
#include "../include/factory.h"
#include "../include/field.h"

void CorrectInputChecker(char& x, int& y, Field& field) {
  while (y > 10 || y < 1 || x > 'j' || x < 'a' || field.FindCoord(x, y)) {
    std::cout << "Неправильный ввод, попробуйте ещё раз. Сюда нельзя поставить корабль" << std::endl;
    std::cin >> x >> y;
  }
}

bool CorrectLinePlacement(std::shared_ptr<IShip> ship) {
  bool gorizontal = true;
  bool vertical = true;
  for (int i = 0; i < ship->cells.size() - 1; ++i) {
    if (ship->cells[i].x != ship->cells[i + 1].x) {
      vertical = false;
    } else if (std::abs(ship->cells[i].y - ship->cells[i + 1].y) != 1) {
      vertical = false;
    }
    if (ship->cells[i].y != ship->cells[i + 1].y) {
      gorizontal = false;
    } else if (std::abs(ship->cells[i].x - ship->cells[i + 1].x) != 1) {
      gorizontal = false;
    }
  }
  if (gorizontal || vertical) {
    return true;
  }
  return false;
}

void Battle::ShipPlacement(Person& person, Fleet& fleet, std::shared_ptr<IShip> ship, int count, int size, Field& field) {
  for (int i = 0; i < count; ++i) {
    std::cout << "Введите координаты для " << size << " палубных кораблей буквы: abc..ij, цифры от 1 до 10" << std::endl;
    std::cout << size << " пары координат по 1 букве и 1 цифре" << std::endl;
    bool first = true;
    while (first || !CorrectLinePlacement(ship)) {
      if (!first) {
        std::cout << "Координаты не соответствуют правилам игры, попробуйте ещё раз" << std::endl;
      }
      first = false;
      ship->cells.clear();
      for (int i = 0; i < size; ++i) {
        char x = 0;
        int y = 0;
        std::cin >> x >> y;
        CorrectInputChecker(x, y, field);
        ship->cells.emplace_back(x, y);
      }
      std::sort(ship->cells.begin(), ship->cells.end(), [](Cell& left, Cell& right) {
        if (left.x < right.x && left.y < right.y) {
          return true;
        }
        if (left.x == right.x && left.y < right.y) {
          return true;
        }
        if (left.x < right.x && left.y == right.y) {
          return true;
        }
        return false;
      });
    }
    std::cout << "Корабль установлен успешно" << std::endl;
    field.PlaceShip(ship);
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
  Field field;
  ShipPlacement(person, fleet, fleet.factory.GetCruiser(), 1, 4, field);
  ShipPlacement(person, fleet, fleet.factory.GetBarge(), 2, 3, field);
  ShipPlacement(person, fleet, fleet.factory.GetCatamaran(), 3, 2, field);
  ShipPlacement(person, fleet, fleet.factory.GetBoat(), 4, 1, field);
}

void CorrectInput(char& x, int& y) {
  while (y > 10 || y < 1 || x > 'j' || x < 'a') {
    std::cout << "Неправильный ввод, попробуйте ещё раз" << std::endl;
    std::cin >> x >> y;
  }
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
    CorrectInput(x, y);
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