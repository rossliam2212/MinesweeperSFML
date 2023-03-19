//
// Created by Liam Ross on 14/03/2023.
//

#ifndef TICTACTOEGUI_BUTTON_H
#define TICTACTOEGUI_BUTTON_H

#include "../utilities/input/Input.h"

enum ButtonStates {
    idle = 0,
    hover,
    active
};

class Button {
private:
    ushort state;

    sf::RectangleShape shape;
    sf::Font* font;
    int fontSize;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    bool display;

public:
    Button(float x, float y, float width, float height, sf::Font* font, int fontSize,
           const std::string& text, sf::Color idleColor, sf::Color hoverColor,
           sf::Color activeColor);

    void update(const sf::Vector2f& mousePos);
    void render(sf::RenderWindow* target);

    bool isPressed() const;
    bool getShouldDisplay() const;
    void setDisplay(bool shouldDisplay);
};


#endif //TICTACTOEGUI_BUTTON_H
