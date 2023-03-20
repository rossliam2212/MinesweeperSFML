//
// Created by Liam Ross on 20/03/2023.
//

#ifndef MINESWEEPERGUI_HOWTOPLAYMENUSTATE_H
#define MINESWEEPERGUI_HOWTOPLAYMENUSTATE_H

#include "State.h"
#include "../../ui/Button.h"


class HowToPlayMenuState : public State {
private:
    sf::Text titleText;
    sf::Font font;
    sf::RectangleShape background;

    std::map<std::string, Button*> buttons;

public:
    HowToPlayMenuState(sf::RenderWindow* window, std::stack<State*>* states) noexcept;
    ~HowToPlayMenuState() override;

    void update() override;
    void render(sf::RenderWindow* window) override;

private:
    void updateButtons();
    void renderButtons(sf::RenderWindow* window);

    void initText();
    void initFont();
    void initBackground();
    void initButtons();
};


#endif //MINESWEEPERGUI_HOWTOPLAYMENUSTATE_H
