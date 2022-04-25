//
// Created by nikita on 25.04.22.
//

#include "../GraphicUI.h"
#include "../constants.h"

GraphicUI::GraphicUI() : window(sf::RenderWindow(sf::VideoMode(app_width, app_height),
                                                 "battleships")) {}