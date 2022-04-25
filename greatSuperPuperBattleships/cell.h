//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_CELL_H
#define BATTLESHIPS_CELL_H
#pragma once
#include "SFML/Graphics.hpp"
#include "constants.h"
#include "vector"
#include "ship.h"
inline std::vector<sf::Color> colorsFromState = {sf::Color::Red, sf::Color::Cyan, sf::Color::Blue,
                                                 sf::Color::White, sf::Color::Black};

struct Position {
    int x;
    int y;
    bool operator ==(Position another) {return x == another.x && y == another.y;}
};
class Ship;
class Cell {
public:
    enum CellState {
        DEAD,
        INJURED,
        EMPTY,
        UNKNOWN,
        SHIP,
    };

    void draw(sf::RenderWindow& window, int position_x, int position_y,bool isSelected);

    void setState(CellState state) { this->state = state; }

    void setShip(Ship& ship) {this->ship = &ship;}

    void setPosition(Position position) { this->position = position; }

    void attack();
private:
    Ship* ship;
    CellState state = UNKNOWN;
    Position position;
};


#endif //BATTLESHIPS_CELL_H
