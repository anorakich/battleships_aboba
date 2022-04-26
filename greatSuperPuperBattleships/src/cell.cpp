//
// Created by nikita on 24.04.22.
//

#include "../cell.h"

Cell::Cell(): state(Cell::EMPTY) {}

void Cell::setState(Cell::CellState _state) {
    state = _state;
}
void Cell::setShip(Ship* ship) { this->ship = ship;}
Cell::CellState Cell::getState() const {
    return state;
}

Ship* Cell::getShip() {
    return ship;
}
