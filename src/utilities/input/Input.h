//
// Created by Liam Ross on 14/03/2023.
//

#ifndef TICTACTOEGUI_INPUT_H
#define TICTACTOEGUI_INPUT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

namespace input {
    class Input {
    public:
        class Mouse {
        private:
            const static sf::RenderWindow* window;

        public:
            static void init(sf::RenderWindow* target);

            static bool mousePressed(sf::Mouse::Button btn);
            static sf::Vector2f getPosition();
            static sf::Vector2f getCoords();
            static sf::Vector2f getRelativePosition();
            static sf::Vector2f getRelativeCoords();

        };
    };
}


#endif //TICTACTOEGUI_INPUT_H
