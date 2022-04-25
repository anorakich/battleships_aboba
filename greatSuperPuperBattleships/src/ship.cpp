//
// Created by nikita on 24.04.22.
//

#include "../ship.h"

Ship::Ship(ShipType type): sz(type), hp(type), state(Ship::OK) {}

void Ship::addCell(Cell* cell) {
    cells.push_back(cell);
}