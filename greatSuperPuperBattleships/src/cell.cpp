#include "../cell.h"

Cell::Cell(): state(Cell::EMPTY) {}

void Cell::setState(Cell::CellState _state) {
    state = _state;
}

void Cell::setShip(Ship* _ship) {
    ship = _ship;
    state = SHIP;
}

Cell::CellState Cell::getState() const {
    return state;
}

Ship* Cell::getShip() const {
    return ship;
}

bool Cell::getIsHited() const {
    return isHited;
}

void Cell::setIsHited(bool _isHited) {
    isHited = _isHited;
}
