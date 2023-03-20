//
// Created by Liam Ross on 20/03/2023.
//

#include "HowToPlayMenuState.h"

HowToPlayMenuState::HowToPlayMenuState(sf::RenderWindow* window, std::stack<State*>* states) noexcept
    : State(window, states) {
    initFont();
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
}

void HowToPlayMenuState::initFont() {
    if (!font.loadFromFile(FONT_PATH)) {
        logger.error("Could not load font from file.", this);
        return;
    }
    logger.info("Loaded font.", this);
}

void HowToPlayMenuState::initBackground() {
    background.setSize(sf::Vector2f{static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)});
    background.setFillColor(sf::Color{40, 40, 40, 255});
}

void HowToPlayMenuState::initButtons() {
    buttons["Back"] = new Button {
            100,
            1000,
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
