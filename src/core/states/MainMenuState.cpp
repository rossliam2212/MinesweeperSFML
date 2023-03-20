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
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, oneBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["threeBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, threeBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["fiveBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, fiveBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["tenBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, tenBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["twentyBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, twentyBomb});
        delayForMilliSeconds(500);
    }

    if (buttons["thirtyFiveBombs"]->isPressed()) {
        logger.info("Starting GameState.", this);
        states->push(new GameState{window, states, thirtyFiveBomb});
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
 * Initializes the font.
 */
void MainMenuState::initFonts() {
    if (!font.loadFromFile(FONT_PATH)) {
        logger.error("Could not load font from file.", this);
        return;
    }
    logger.info("Loaded font.", this);
}

/**
 * Initializes all of the buttons.
 */
void MainMenuState::initButtons() {
//    buttons["Play"] = new Button {
//            100,
//            350,
//            250,
//            75,
//            &font,
//            24,
//            "Play",
//            sf::Color{0, 0, 0, 255},
//            sf::Color{50, 50, 50, 255},
//            sf::Color::White
//    };

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

    buttons["fiveBombs"] = new Button {
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

    buttons["tenBombs"] = new Button {
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

    buttons["twentyBombs"] = new Button {
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

    buttons["thirtyFiveBombs"] = new Button {
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

    buttons["Quit"] = new Button {
            400,
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
