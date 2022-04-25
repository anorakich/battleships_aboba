//
// Created by nikita on 24.04.22.
//

#include "../cell.h"

Cell::Cell(): state(Cell::EMPTY) {}

void Cell::setState(Cell::CellState _state) {
    state = _state;
}

Cell::CellState Cell::getState() const {
    return state;
}
