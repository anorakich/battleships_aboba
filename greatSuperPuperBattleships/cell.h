//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_CELL_H
#define BATTLESHIPS_CELL_H
#pragma once

#include "constants.h"
#include "vector"
#include "ship.h"

struct Position {
    int x;
    int y;
    bool operator==(Position another) {return x == another.x && y == another.y;}
};

class Ship;
class Cell {
public:
    enum CellState {
        DEAD,
        INJURED,
        EMPTY,
        SHIP,
    };

    Cell();
    void setState(CellState _state);
    CellState getState();
//    void setShip(Ship* ship);

private:
    CellState state;
//    Ship* ship;
};

#endif //BATTLESHIPS_CELL_H
