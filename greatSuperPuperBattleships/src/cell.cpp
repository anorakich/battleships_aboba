//
// Created by nikita on 24.04.22.
//

#include "../cell.h"

void Cell::draw(sf::RenderWindow& window, int position_x, int position_y, bool isSelected) {
    sf::RectangleShape rectangle({(float) size_of_cell, (float) size_of_cell});
    rectangle.setPosition(position_x, position_y);
    rectangle.setOutlineThickness(4);
    rectangle.setFillColor(colorsFromState[state]);
    if (isSelected)
        rectangle.setOutlineColor(sf::Color::Magenta);
    else
        rectangle.setOutlineColor(sf::Color::Black);
    window.draw(rectangle);
}

void Cell::attack() {
    if (state == SHIP) {
        state = DEAD;
        ship->decreaseHP();
    }
}