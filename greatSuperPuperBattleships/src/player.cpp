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
    
}
