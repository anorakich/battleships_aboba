//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_PLAYER_H
#define BATTLESHIPS_PLAYER_H

#include <string>
#include "field.h"
#include "UI.h"

class Player {
public:
    Player();
    void set_name(std::string _name);
    void set_field(Field* _field);
    void set_ui(UI* _ui);
    UI* get_ui();
    Field* get_field();
    void keep_attack(Cell* cell);
    bool is_losed();
private:
    std::string name;
    Field* field;
    UI* ui;
    std::vector<Ship*> ships;
    size_t ships_count = 10;
    size_t alive_ships_count = 10;
};


#endif //BATTLESHIPS_PLAYER_H
