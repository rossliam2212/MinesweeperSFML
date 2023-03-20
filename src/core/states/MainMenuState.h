//
// Created by Liam Ross on 16/03/2023.
//

#ifndef MINESWEEPERGUI_MAINMENUSTATE_H
#define MINESWEEPERGUI_MAINMENUSTATE_H

#include "GameState.h"
#include "HowToPlayMenuState.h"

#include "../../ui/Button.h"

class MainMenuState : public State {
private:
    sf::Text titleText;
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    ~MainMenuState() override;

    void update() override;
    void render(sf::RenderWindow* window) override;

private:
    void updateButtons();
    void renderButtons(sf::RenderWindow* window);

    void initText();
    void initBackground();
    void initFonts();
    void initButtons();
};


#endif //MINESWEEPERGUI_MAINMENUSTATE_H
