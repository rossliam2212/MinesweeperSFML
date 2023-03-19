//
// Created by Liam Ross on 14/03/2023.
//

#include "Input.h"

namespace input {

    const sf::RenderWindow* Input::Mouse::window;

    void Input::Mouse::init(sf::RenderWindow* target) {
        window = target;
    }

    bool Input::Mouse::mousePressed(sf::Mouse::Button btn) {
        return sf::Mouse::isButtonPressed(btn);
    }

    sf::Vector2f Input::Mouse::getPosition() {
        if (!window->getSystemHandle())
            return {};
        return (sf::Vector2f)sf::Mouse::getPosition();
    }

    sf::Vector2f Input::Mouse::getCoords() {
        if (!window->getSystemHandle())
            return {};
        return window->mapPixelToCoords(sf::Mouse::getPosition());
    }

    sf::Vector2f Input::Mouse::getRelativePosition() {
        if (!window->getSystemHandle())
            return {};
        return (sf::Vector2f)sf::Mouse::getPosition(*window);
    }

    sf::Vector2f Input::Mouse::getRelativeCoords() {
        if (!window->getSystemHandle())
            return {};
        return window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    }
}