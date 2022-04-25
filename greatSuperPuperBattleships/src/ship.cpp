//
// Created by nikita on 24.04.22.
//

#include "../ship.h"
void Ship::decreaseHP() {
    --HP;
    if (HP == 0) {
        state = DEAD;
        for (auto cell : cells)
            cell->setState(Cell::DEAD);
    }
}