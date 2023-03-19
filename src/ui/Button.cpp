//
// Created by Liam Ross on 14/03/2023.
//

#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, int fontSize, const std::string& text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
        : state{idle},
          font{font},
          fontSize{fontSize},
          idleColor{idleColor},
          hoverColor{hoverColor},
          activeColor{activeColor},
          display{true} {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f{width, height});
    shape.setFillColor(idleColor);

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(fontSize);
    this->text.setPosition(
            shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );
}

void Button::update(const sf::Vector2f& mousePos) {
    state = idle;

    if (shape.getGlobalBounds().contains(mousePos)) {
        state = hover;

        if (input::Input::Mouse::mousePressed(sf::Mouse::Left)) {
            state = active;
        }
    }

    switch (state) {
        case idle:
        default:
            shape.setFillColor(idleColor);
            text.setFillColor(sf::Color::White);
            break;
        case hover:
            shape.setFillColor(hoverColor);
            text.setFillColor(sf::Color::White);
            break;
        case active:
            shape.setFillColor(activeColor);
            text.setFillColor(sf::Color::Black);
            break;
    }
}

void Button::render(sf::RenderWindow* target) {
    target->draw(shape);
    target->draw(text);
}

bool Button::isPressed() const {
    return state == active;
}

bool Button::getShouldDisplay() const {
    return display;
}

void Button::setDisplay(bool shouldDisplay) {
    display = shouldDisplay;
}