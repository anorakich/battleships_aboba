#include "../customText.h"

CustomText::CustomText(const std::string& text, const sf::Font& font, int position_x, int position_y):
        text_object(text, font) {
    text_object.setPosition(position_x - text_object.getGlobalBounds().width / 2, position_y);
}

void CustomText::draw(sf::RenderWindow& app) const {
    app.draw(text_object);
}

void CustomText::setColor(const sf::Color& color) {
    text_object.setFillColor(color);
}