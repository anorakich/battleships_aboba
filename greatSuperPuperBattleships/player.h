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
private:
    std::string name;
    Field* field;
    UI* ui;
    std::vector<Ship> ships;
};


#endif //BATTLESHIPS_PLAYER_H
