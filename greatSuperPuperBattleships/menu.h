//
// Created by nikita on 16.04.22.
//

#ifndef BATTLESHIPS_MENU_H
#define BATTLESHIPS_MENU_H


class Menu {
    enum Menu_State {
        EXIT,
        PLAY,
        SETTINGS,
    };
    Menu_State menu_state = EXIT;
public:
    Menu();
};


#endif //BATTLESHIPS_MENU_H
