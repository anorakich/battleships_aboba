#pragma once
#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H

#include "cell.h"
#include "vector"

class Cell;

class Ship {
public:
    enum ShipState {
        INJURED,
        DEAD,
        OK,
    };
    enum ShipType {
        ONEDECK,
        TWODECK,
        THREEDECK,
        FOURDECK,
    };

    explicit Ship(ShipType type);

    void addCell(Cell* cell);


    void deal_damage(size_t damage);

    ShipState getState();

private:
    std::vector<Cell*> cells;
    size_t sz;
    size_t hp;
    ShipState state;
};


#endif //BATTLESHIPS_SHIP_H
