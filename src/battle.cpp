
#include <iostream>
#include "../battle.h"
#include "../ship_4.h"
#include "../ship_1.h"
#include "../ship_2.h"
#include "../ship_3.h"

void Battle::ShipPlacement(Person& person, std::shared_ptr<IShip> ship, int count, int size) {
  for (int i = 0; i < count; ++i) {
    std::cout << "Введите координаты для " << size << " палубных кораблей буквы: abc..ij, цифры от 1 до 10" << std::endl;
    std::cout << size << " пары координат по 1 букве и 1 цифре" << std::endl;
    for (int i = 0; i < size; ++i) {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      char x = 0;
      int y = 0;
      std::cin >> x >> y;
      if (y > 10 || y < 1 || x > 'j' || x < 'a') {
        std::cout << "Неправильный ввод, ввод" << std::endl;
        ShipPlacement(person, ship, count, size);
      }
      ship->v.emplace_back(x, y);
    }
    std::cout << "Корабль установлен успешно" << std::endl;
    person.flot.ships.push_back(ship);
  }
}

void Battle::Registration(Person& person) {
  std::cout << "Здравствуйте, это игра Морской бой, пожалуйста, зарегестрируйтесь" << std::endl;
  std::cout << "Введите ваше имя или ник" << std::endl;
  std::cin >> person.name;
  std::cout << "Придумайте пароль для входа в систему" << std::endl;
  std::cin >> person.password;
  std::cout << "Регистрация завершена, приступите к расстановке кораблей" << std::endl;

  ShipPlacement(person, person.flot.ship4, 1, 4);
  //ShipPlacement(person, ship_3, 2, 3);
  //ShipPlacement(person, ship_2, 3, 2);
  //ShipPlacement(person, ship_1, 4, 1);
}

void Battle::Game(Person& person, Person& second) {
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
  for (int i = 0; i < person.flot.ships.size(); ++i) {
    shot = person.flot.ships[i]->Search(x, y);
    if (shot) {
      std::cout << "Попал" << std::endl;
      if (person.flot.ships[i]->Dead()) {
        std::cout << "Корабль убит" << std::endl;
      }
      break;
    }
  }
  if (!shot) {
    std::cout << "Мимо" << std::endl;
  }
  if (shot) {
    Game(person, second);
  }
  Game(second, person);
}

void Battle::Start() {
  Registration(first);

  Registration(second);
  Game(first, second);

}
