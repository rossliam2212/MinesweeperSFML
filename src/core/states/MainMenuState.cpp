//
// Created by Liam Ross on 16/03/2023.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) noexcept
        : State(window, states) {
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

/**
 * Renders all of the MainMenuState components to the window.
 * @param window The window to draw on.
 */
void MainMenuState::render(sf::RenderWindow* window) {
    window->draw(background);
    renderButtons(window);
    window->draw(titleText);
}

/**
 * Updates each button with the current position of the mouse and checks whether a button is pressed.
 */
void MainMenuState::updateButtons() {
    for (auto& btn : buttons)
        btn.second->update(mousePosView);

    // TODO have buttons for each of the game modes
    if (buttons["OneBomb"]->isPressed()) {
        logger.info("Starting GameState. GameMode: 1 bomb.", this);
        states->push(new GameState{window, states, oneBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["ThreeBombs"]->isPressed()) {
        logger.info("Starting GameState. GameMode: 3 bombs.", this);
        states->push(new GameState{window, states, threeBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["FiveBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, fiveBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["TenBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, tenBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["TwentyBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, twentyBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["ThirtyFiveBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, thirtyFiveBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["HowToPlay"]->isPressed()) {
        logger.info("Starting HowToPlayMenuState.", this);
        states->push(new HowToPlayMenuState{window, states});
        delayForMilliSeconds(500);
    }

    if (buttons["Quit"]->isPressed()) {
        logger.info("Ending state.", this);
        endState();
    }
}

/**
 * Renders the buttons to the window.
  * @param window The window to render the buttons on.
 */
void MainMenuState::renderButtons(sf::RenderWindow* window) {
    for (auto& btn : buttons)
        btn.second->render(window);
}

/**
 * Initializes the text.
 */
void MainMenuState::initText() {
    titleText.setPosition(100, 200);
    titleText.setFont(font);
    titleText.setCharacterSize(96);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("Minesweeper");
}

/**
 * Initializes the background.
 */
void MainMenuState::initBackground() {
    background.setSize(sf::Vector2f{static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)});
    background.setFillColor(sf::Color{40, 40, 40, 255});
}

/**
 * Initializes all of the buttons.
 */
void MainMenuState::initButtons() {
    buttons["OneBomb"] = new Button {
            100,
            350,
            250,
            75,
            &font,
            24,
            "One Bomb",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["ThreeBombs"] = new Button {
            100,
            500,
            250,
            75,
            &font,
            24,
            "Three Bombs",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["FiveBombs"] = new Button {
            100,
            650,
            250,
            75,
            &font,
            24,
            "Five Bombs",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["TenBombs"] = new Button {
            500,
            350,
            250,
            75,
            &font,
            24,
            "Ten Bombs",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["TwentyBombs"] = new Button {
            500,
            500,
            250,
            75,
            &font,
            24,
            "Twenty Bombs",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["ThirtyFiveBombs"] = new Button {
            500,
            650,
            250,
            75,
            &font,
            24,
            "Thirty Five Bombs",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["HowToPlay"] = new Button {
            100,
            1200,
            250,
            75,
            &font,
            24,
            "How To Play",
            sf::Color{0, 0, 0, 255},
            sf::Color{50, 50, 50, 255},
            sf::Color::White
    };

    buttons["Quit"] = new Button {
            500,
            1200,
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
