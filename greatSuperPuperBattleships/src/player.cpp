//
// Created by nikita on 24.04.22.
//

#include "../player.h"
#include "../ship.h"

Player::Player() {

}

void Player::setShip(Ship::ShipType type) {
    Ship ship(type);
    while (true) {
        Position start = ui->getPosition();
        Position end = ui->getPosition();
        if (start.x == end.x && abs(start.y - end.y) == type) {
            if (start.y > end.y)
                std::swap(start, end);
            for (int i = 0; i < type; ++i) {
                ship.addCell(&field->at(start.y + i, start.x));
            }
        } else if (start.y == end.y && abs(start.x - end.x) == type) {
            if (start.x > end.x)
                std::swap(start, end);
            for (int i = 0; i < type; ++i) {
                ship.addCell(&field->at(start.y, start.x + i));
            }
        }
    }

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

}
