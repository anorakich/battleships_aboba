#include "../customText.h"

CustomText::CustomText(const std::string& text, const sf::Font& font, int position_x, int position_y):
        textObject(text, font) {
    textObject.setPosition(position_x - textObject.getGlobalBounds().width / 2, position_y);
}

void CustomText::draw(sf::RenderWindow& app) const {
    app.draw(textObject);
}

void CustomText::setColor(const sf::Color& color) {
    textObject.setFillColor(color);
}