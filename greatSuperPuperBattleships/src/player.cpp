//
// Created by nikita on 24.04.22.
//

#include "../player.h"

Player::Player() {

}

void Player::set_name(std::string _name) {
    name = _name;
}

void Player::set_field(Field* _field) {

}

void Player::set_ui(UI* _ui) {

}

UI *Player::get_ui() {
    return ui;
}

Field *Player::get_field() {
    return field;
}

void Player::keep_attack(Cell *cell) {
    if (!cell->getIsHited()) return;
    cell->setIsHited(true);
    if (cell->getState() == Cell::EMPTY) return;
    if (cell->getState() == Cell::SHIP) {
        cell->setState(Cell::INJURED);
        Ship* ship = cell->getShip();
        ship->deal_damage(1);
        if (ship->getState() == Ship::DEAD) {
            alive_ships_count -= 1;
        }
    }
}

bool Player::is_losed() {
    return alive_ships_count == 0;
}
