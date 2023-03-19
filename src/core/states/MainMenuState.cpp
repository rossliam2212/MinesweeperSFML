//
// Created by Liam Ross on 16/03/2023.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
        : State(window, states) {
    initFonts();
    initButtons();
    initBackground();
    initText();
}

MainMenuState::~MainMenuState() {
    for (auto& button : buttons)
        delete button.second;
}

void MainMenuState::update() {
    updateMousePositions();
    updateButtons();
}

void MainMenuState::render(sf::RenderWindow* window) {
    window->draw(background);
    renderButtons();
    window->draw(titleText);
}

void MainMenuState::updateButtons() {
    for (auto& btn : buttons)
        btn.second->update(mousePosView);

    // TODO have buttons for each of the game modes
    if (buttons["Play"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, oneBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["Quit"]->isPressed()) {
        logger.info("Ending state.", this);
        endState();
    }
}

void MainMenuState::renderButtons() {
    for (auto& btn : buttons)
        btn.second->render(window);
}

void MainMenuState::initText() {
    titleText.setPosition(100, 200);
    titleText.setFont(font);
    titleText.setCharacterSize(96);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("Minesweeper");
}

void MainMenuState::initBackground() {
    background.setSize(sf::Vector2f{static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)});
    background.setFillColor(sf::Color{40, 40, 40, 255});
}

void MainMenuState::initFonts() {
    if (!font.loadFromFile(FONT_PATH)) {
        logger.error("Could not load font from file.", this);
        return;
    }
    logger.info("Loaded font.", this);
}

void MainMenuState::initButtons() {
    buttons["Play"] = new Button {
            100,
            350,
            250,
            75,
            &font,
            24,
            "Play",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["Quit"] = new Button {
            400,
            350,
            250,
            75,
            &font,
            24,
            "Quit",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };
}
