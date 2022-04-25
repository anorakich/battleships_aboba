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

    void deal_damage();

    void addCell(Cell* cell);
private:
    std::vector<Cell*> cells;
    size_t sz;
    size_t hp;
    ShipState state;
};


#endif //BATTLESHIPS_SHIP_H
