#pragma once
#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H

#include "cell.h"
#include "vector"
enum ShipState{
    INJURED,
    DEAD,
    OK,
};
class Cell;
class Ship {
public:
    void decreaseHP();
private:
    std::vector<Cell*> cells;
    int HP = cells.size();
    ShipState state = OK;
};


#endif //BATTLESHIPS_SHIP_H
