#include "../ship.h"

Ship::Ship(ShipType type): sz(type + 1), hp(type + 1), state(Ship::OK) {}

void Ship::addCell(Cell* cell) {
    cells.push_back(cell);
    cell->setShip(this);
}

void Ship::deal_damage(size_t damage) {
    if (damage > hp) {
        hp = 0;
    } else {
        hp -= damage;
    }

    if (hp == 0 && state != DEAD) {
        for (size_t i = 0; i < sz; ++i) {
            cells[i]->setState(Cell::DEAD);
        }
        state = DEAD;
    } else if (hp < sz && state != INJURED) {
        state = INJURED;
    }
}

Ship::ShipState Ship::getState() const {
    return state;
}
