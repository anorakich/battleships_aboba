//
// Created by nikita on 16.04.22.
//

#include "../field.h"

Field::Field() : field(10, std::vector<FieldState>(10, UNKNOWN)) {}

void Field::set_ship(const Ship& ship) {
    std::vector<block> shipCoordinates = ship.getBlocksPosition();
    for (size_t i = 0; i < ship.getShipSize(); ++i) {
        field[shipCoordinates[i].pos_y][shipCoordinates[i].pos_x] = SHIP;
    }
}