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

    bool operator==(Position another) { return x == another.x && y == another.y; }
    bool operator!=(Position another) {return !(*this == another);}
    Position(int x, int y) : x(x), y(y) {}
    Position() = default;

    void read() {
        char pos_x;
        char pos_y;
        std::cin >> pos_x;
        std::cin >> pos_y;
        x = pos_x - 'a';
        y = pos_y - '1';
    }

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
    void setShip(Ship* ship);
    Ship* getShip();
    bool getIsHited();
    void setIsHited(bool _isHited);
private:
    CellState state;
    Ship* ship;
    bool isHited;
};

#endif //BATTLESHIPS_CELL_H
