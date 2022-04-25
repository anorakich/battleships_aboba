//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_CELL_H
#define BATTLESHIPS_CELL_H
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "constants.h"
#include "vector"
#include "ship.h"

inline std::vector<sf::Color> colorsFromState = {sf::Color::Red, sf::Color::Cyan, sf::Color::Blue,
                                                 sf::Color::White, sf::Color::Black};

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
        DEAD = 0,
        INJURED = 1,
        EMPTY = 2,
        SHIP = 3,
    };

    void draw(sf::RenderWindow& window, int position_x, int position_y, bool isSelected);

    void setState(CellState state) { this->state = state; }

    void setShip(Ship& ship) { this->ship = &ship; }

    void setPosition(Position position) { this->position = position; }

    void attack();

    CellState getState() const { return state; }

private:
    Ship* ship;
    CellState state = EMPTY;
    Position position;
};


#endif //BATTLESHIPS_CELL_H
