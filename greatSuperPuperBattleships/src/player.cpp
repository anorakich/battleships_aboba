#include "../player.h"

Player::Player(size_t _id): id(_id), ships_count(count_of_ships),
    alive_ships_count(count_of_ships) {
    ships.reserve(100);
}

void Player::setName(std::string _name) {
    name = _name;
}

void Player::setField(Field* _field) {
    field = _field;
}

void Player::setUi(UI* _ui) {
    ui = _ui;
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
    ui->waitForNextTurn();
}

std::string Player::getName() const {
    return name;
}

UI* Player::getUi() const {
    return ui;
}

Field* Player::getField() const {
    return field;
}

size_t Player::getId() const {
    return id;
}

void Player::keep_attack(Position position) {
    Cell* cell = field->at(position.y, position.x);
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

Position Player::attack(Field *enemy_field) {
    ui->displayField(*enemy_field, true);
    return ui->getPosition();
}

bool Player::is_losed() const {
    return alive_ships_count == 0;
}