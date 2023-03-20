//
// Created by Liam Ross on 20/03/2023.
//

#include "HowToPlayMenuState.h"

HowToPlayMenuState::HowToPlayMenuState(sf::RenderWindow* window, std::stack<State*>* states) noexcept
    : State(window, states) {
    initText();
    initBackground();
    initButtons();
}

HowToPlayMenuState::~HowToPlayMenuState() {
    for (auto& btn : buttons)
        delete btn.second;
}

void HowToPlayMenuState::update() {
    updateMousePositions();
    updateButtons();
}

void HowToPlayMenuState::updateButtons() {
    for (auto& btn : buttons)
        btn.second->update(mousePosView);

    if (buttons["Back"]->isPressed()) {
        logger.info("Ending state.", this);
        endState();
    }
}

void HowToPlayMenuState::render(sf::RenderWindow* window) {
    window->draw(background);
    window->draw(titleText);
    window->draw(infoText);
    renderButtons(window);
}

void HowToPlayMenuState::renderButtons(sf::RenderWindow* window) {
    for (auto& btn : buttons)
        if (btn.second->getShouldDisplay())
            btn.second->render(window);
}

void HowToPlayMenuState::initText() {
    titleText.setPosition(100, 200);
    titleText.setFont(font);
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("*How To Play Minesweeper*");

    infoText.setPosition(100, 400);
    infoText.setFont(font);
    infoText.setCharacterSize(30);
    infoText.setFillColor(sf::Color::White);

    std::ostringstream oss;
    oss << "- When you select a game mode, that number of bombs will be added to the board.\n\n";

    oss << "- When the game starts, the game board will be displayed and all the positions will be\n";
    oss << "  covered. You must click on a position to reveal it.\n\n";

    oss << "- When a position is revealed, you will either see a bomb or a number from 1 to 8.\n\n";

    oss << "- If the position you reveal contains a number, this means that there are that many bombs\n";
    oss << "  currently touching that position.\n";
    oss << "  For example, if you reveal, this tells you that there are 3 bombs touching that position\n";
    oss << "  and can be anywhere in the:\n";
    oss << "  \tthree, if it's a corner,\n";
    oss << "  \tfive, if it's a side, or\n";
    oss << "  \teight, otherwise,\n";
    oss << "  positions around the position you opened.\n\n";

    oss << "- You must use the numbers you reveal to you advantage to navigate your way around the board.\n\n";

    oss << "- If you reveal a bomb, the game is over!\n\n";

    oss << "- Good Luck!";

    infoText.setString(oss.str());

}

void HowToPlayMenuState::initBackground() {
    background.setSize(sf::Vector2f{static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)});
    background.setFillColor(sf::Color{40, 40, 40, 255});
}

void HowToPlayMenuState::initButtons() {
    buttons["Back"] = new Button {
            100,
            1300,
            250,
            75,
            &font,
            24,
            "Back",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };
}
