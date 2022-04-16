//
// Created by nikita on 16.04.22.
//

#ifndef BATTLESHIPS_FIELD_H
#define BATTLESHIPS_FIELD_H

#include <vector>
#include "ship.h"

class Field {
private:
    enum FieldState {
        DEAD,
        INJURED,
        EMPTY,
        UNKNOWN,
        SHIP,
    };
    std::vector<std::vector<FieldState>> field;

    Field();

    void set_ship(const Ship& ship);
};


#endif //BATTLESHIPS_FIELD_H
