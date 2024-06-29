
#include "../include/field.h"

void Field::PlaceShip(const std::shared_ptr<IShip>& ship) {
  std::vector<int> dx{-1, 0, 1};
  for (auto& cell : ship->cells) {
    for (auto ddx : dx) {
      for (auto ddy : dx) {
        if (cell.x - 'a' + ddx >= 0 && cell.y + ddy >=0 && cell.x - 'a' + ddx < 10 &&  cell.y + ddy < 10) {
          field[cell.x - 'a' + ddx][cell.y + ddy] = 1;
        }
      }
    }
  }
}

bool Field::FindCoord(char x, int y) {
  return field[x - 'a'][y] == 1;
}
