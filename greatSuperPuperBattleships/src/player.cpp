//
// Created by nikita on 24.04.22.
//

#include "../player.h"
#include "../ship.h"

Player::Player() {
    ships.reserve(100);
}

void Player::setShip(Ship::ShipType type) {
    ui->displayField(*field, false);
    Ship* ship = new Ship(type);
    while (true) {
        Position start = ui->getPosition();
        Position end = ui->getPosition();
        if (start.x == end.x && abs(start.y - end.y) == type) {
            if (start.y > end.y)
                std::swap(start, end);
            for (int i = 0; i <= type; ++i) {
                ship->addCell(field->at(start.y + i, start.x));
            }
            ships.push_back(ship);
            break;
        } else if (start.y == end.y && abs(start.x - end.x) == type) {
            if (start.x > end.x)
                std::swap(start, end);
            for (int i = 0; i <= type; ++i) {
                ship->addCell(field->at(start.y, start.x + i));
            }
            ships.push_back(ship);
            break;
        }
    }
    ui->displayField(*field,false);
}

void Player::set_name(std::string _name) {
    name = _name;
}

void Player::set_field(Field* _field) {
    field = _field;
}

void Player::set_ui(UI* _ui) {
    ui = _ui;
}

UI* Player::get_ui() {
    return ui;
}

Field* Player::get_field() {
    return field;
}

void Player::keep_attack(Cell* cell) {
    if (cell->getIsHited()) return;
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