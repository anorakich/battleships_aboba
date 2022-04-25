#pragma once
#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H

#include "cell.h"
#include "vector"

class Cell;
class Ship {
public:
    enum ShipState{
        INJURED,
        DEAD,
        OK,
    };

    explicit Ship(size_t _sz);
    void deal_damage();
private:
    std::vector<Cell*> cells;
    size_t sz;
    size_t hp;
    ShipState state;
};


#endif //BATTLESHIPS_SHIP_H
