#include "../include/boat.h"


bool Boat::isDead() const {
    int alive = 0;
    for (auto ship : cells) {
        if (!ship.dead) {
            ++alive;
        }
    }
    if (alive) {
        return false;
    }
    return true;
}

bool Boat::Search(char str, int yy) {
    bool search = false;
    for (auto &ship: cells) {
        if (ship.x == str && ship.y == yy) {
            ship.dead = true;
            search = true;
        }
    }
    return search;
}