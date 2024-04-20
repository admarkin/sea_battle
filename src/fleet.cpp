#include "../include/fleet.h"

bool Fleet::isAllShipsDead() {
    bool dead = true;
    for (const auto& ship : ships) {
        if (!ship->isDead()) {
            dead = false;
        }
    }
    return dead;
}