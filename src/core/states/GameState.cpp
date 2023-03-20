//
// Created by Liam Ross on 16/03/2023.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, GameMode gameMode) noexcept
    : State{window, states},
      board{gameMode},
      gameOver{false} {
    initText();
    initBackground();
    initButtons();
    initGrid();
}

GameState::~GameState() {
    for (auto& btn : buttons)
        delete btn.second;
}

void GameState::update() {
    updateMousePositions();
    updateText();
    updateButtons();
    board.update();
}

/**
 * Updates each button with the current position of the mouse and checks whether a button is pressed.
 */
void GameState::updateButtons() {
    for (auto& btn : buttons)
        btn.second->update(mousePosView);

    if (!gameOver) {
        if (buttons["Position1"]->isPressed() && buttons["Position1"]->getShouldDisplay()) {
            buttons["Position1"]->setDisplay(false);
            handleMove(1);
        }

        if (buttons["Position2"]->isPressed() && buttons["Position2"]->getShouldDisplay()) {
            buttons["Position2"]->setDisplay(false);
            handleMove(2);
        }

        if (buttons["Position3"]->isPressed() && buttons["Position3"]->getShouldDisplay()) {
            buttons["Position3"]->setDisplay(false);
            handleMove(3);
        }

        if (buttons["Position4"]->isPressed() && buttons["Position4"]->getShouldDisplay()) {
            buttons["Position4"]->setDisplay(false);
            handleMove(4);
        }

        if (buttons["Position5"]->isPressed() && buttons["Position5"]->getShouldDisplay()) {
            buttons["Position5"]->setDisplay(false);
            handleMove(5);
        }

        if (buttons["Position6"]->isPressed() && buttons["Position6"]->getShouldDisplay()) {
            buttons["Position6"]->setDisplay(false);
            handleMove(6);
        }

        if (buttons["Position7"]->isPressed() && buttons["Position7"]->getShouldDisplay()) {
            buttons["Position7"]->setDisplay(false);
            handleMove(7);
        }

        if (buttons["Position8"]->isPressed() && buttons["Position8"]->getShouldDisplay()) {
            buttons["Position8"]->setDisplay(false);
            handleMove(8);
        }

        if (buttons["Position9"]->isPressed() && buttons["Position9"]->getShouldDisplay()) {
            buttons["Position9"]->setDisplay(false);
            handleMove(9);
        }

        if (buttons["Position10"]->isPressed() && buttons["Position10"]->getShouldDisplay()) {
            buttons["Position10"]->setDisplay(false);
            handleMove(10);
        }

        if (buttons["Position11"]->isPressed() && buttons["Position11"]->getShouldDisplay()) {
            buttons["Position11"]->setDisplay(false);
            handleMove(11);
        }

        if (buttons["Position12"]->isPressed() && buttons["Position12"]->getShouldDisplay()) {
            buttons["Position12"]->setDisplay(false);
            handleMove(12);
        }

        if (buttons["Position13"]->isPressed() && buttons["Position13"]->getShouldDisplay()) {
            buttons["Position13"]->setDisplay(false);
            handleMove(13);
        }

        if (buttons["Position14"]->isPressed() && buttons["Position14"]->getShouldDisplay()) {
            buttons["Position14"]->setDisplay(false);
            handleMove(14);
        }

        if (buttons["Position15"]->isPressed() && buttons["Position15"]->getShouldDisplay()) {
            buttons["Position15"]->setDisplay(false);
            handleMove(15);
        }

        if (buttons["Position16"]->isPressed() && buttons["Position16"]->getShouldDisplay()) {
            buttons["Position16"]->setDisplay(false);
            handleMove(16);
        }

        if (buttons["Position17"]->isPressed() && buttons["Position17"]->getShouldDisplay()) {
            buttons["Position17"]->setDisplay(false);
            handleMove(17);
        }

        if (buttons["Position18"]->isPressed() && buttons["Position18"]->getShouldDisplay()) {
            buttons["Position18"]->setDisplay(false);
            handleMove(18);
        }

        if (buttons["Position19"]->isPressed() && buttons["Position19"]->getShouldDisplay()) {
            buttons["Position19"]->setDisplay(false);
            handleMove(19);
        }

        if (buttons["Position20"]->isPressed() && buttons["Position20"]->getShouldDisplay()) {
            buttons["Position20"]->setDisplay(false);
            handleMove(20);
        }

        if (buttons["Position21"]->isPressed() && buttons["Position21"]->getShouldDisplay()) {
            buttons["Position21"]->setDisplay(false);
            handleMove(21);
        }

        if (buttons["Position22"]->isPressed() && buttons["Position22"]->getShouldDisplay()) {
            buttons["Position22"]->setDisplay(false);
            handleMove(22);
        }

        if (buttons["Position23"]->isPressed() && buttons["Position23"]->getShouldDisplay()) {
            buttons["Position23"]->setDisplay(false);
            handleMove(23);
        }

        if (buttons["Position24"]->isPressed() && buttons["Position24"]->getShouldDisplay()) {
            buttons["Position24"]->setDisplay(false);
            handleMove(24);
        }

        if (buttons["Position25"]->isPressed() && buttons["Position25"]->getShouldDisplay()) {
            buttons["Position25"]->setDisplay(false);
            handleMove(25);
        }

        if (buttons["Position26"]->isPressed() && buttons["Position26"]->getShouldDisplay()) {
            buttons["Position26"]->setDisplay(false);
            handleMove(26);
        }

        if (buttons["Position27"]->isPressed() && buttons["Position27"]->getShouldDisplay()) {
            buttons["Position27"]->setDisplay(false);
            handleMove(27);
        }

        if (buttons["Position28"]->isPressed() && buttons["Position28"]->getShouldDisplay()) {
            buttons["Position28"]->setDisplay(false);
            handleMove(28);
        }

        if (buttons["Position29"]->isPressed() && buttons["Position29"]->getShouldDisplay()) {
            buttons["Position29"]->setDisplay(false);
            handleMove(29);
        }

        if (buttons["Position30"]->isPressed() && buttons["Position30"]->getShouldDisplay()) {
            buttons["Position30"]->setDisplay(false);
            handleMove(30);
        }

        if (buttons["Position31"]->isPressed() && buttons["Position31"]->getShouldDisplay()) {
            buttons["Position31"]->setDisplay(false);
            handleMove(31);
        }

        if (buttons["Position32"]->isPressed() && buttons["Position32"]->getShouldDisplay()) {
            buttons["Position32"]->setDisplay(false);
            handleMove(32);
        }

        if (buttons["Position33"]->isPressed() && buttons["Position33"]->getShouldDisplay()) {
            buttons["Position33"]->setDisplay(false);
            handleMove(33);
        }

        if (buttons["Position34"]->isPressed() && buttons["Position34"]->getShouldDisplay()) {
            buttons["Position34"]->setDisplay(false);
            handleMove(34);
        }

        if (buttons["Position35"]->isPressed() && buttons["Position35"]->getShouldDisplay()) {
            buttons["Position35"]->setDisplay(false);
            handleMove(35);
        }

        if (buttons["Position36"]->isPressed() && buttons["Position36"]->getShouldDisplay()) {
            buttons["Position36"]->setDisplay(false);
            handleMove(36);
        }
    }
}

/**
 * Updates all of the text.
 */
void GameState::updateText() {
    positionsOpenedText.setString("Positions Opened: " + std::to_string(board.getPositionsOpened()) + "/" + std::to_string(GameBoard::MAX_BOARD_POSITIONS - board.getNumberOfBombs()));
    positionRemainingText.setString("Positions Remaining: " + std::to_string(board.getPositionsRemaining()) + "/" + std::to_string(GameBoard::MAX_BOARD_POSITIONS - board.getNumberOfBombs()));
}

/**
 * Renders all of the GameState components to the window.
 * @param window The window to draw on.
 */
void GameState::render(sf::RenderWindow* window) {
    window->draw(background);
    window->draw(titleText);
    window->draw(numberOfBombsText);
    window->draw(positionsOpenedText);
    window->draw(positionRemainingText);

    if (gameOver)
        window->draw(gameOverText);

    board.render(window);

    renderButtons(window);

    // Rendering the grid.
    for (const auto& line : grid)
        window->draw(line);
}

/**
 * Renders the buttons to the window.
 * @param window The window to render the buttons on.
 */
void GameState::renderButtons(sf::RenderWindow* window) {
    for (auto& btn : buttons)
        if (btn.second->getShouldDisplay())
            btn.second->render(window);
}

void GameState::handleMove(int position) {
    logger.info("Player opening position " + std::to_string(position) + ".", this);
    board.handlePlayerMove(position);
    checkGameOver();
}

void GameState::checkGameOver() {
    if (board.checkIfLoss()) {
        gameOver = true;

        logger.info("Game over, Player loses.", this);
        hideAllButtons();
        // Display Loss UI
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setString("Hard Luck, You Lose!");

    } else if (board.checkIfWon()) {
        gameOver = true;

        logger.info("Game over, Player wins.", this);
        hideAllButtons();

        // Display Win UI
        gameOverText.setFillColor(sf::Color::Green);
        gameOverText.setString("Congrats, You Win!!");
    }
}

/**
 * Hides all the buttons to show the positions of all the bombs when the game is over.
 */
void GameState::hideAllButtons() {
    for (auto& btn : buttons)
        btn.second->setDisplay(false);
}

/**
 * Initializes the text.
 */
void GameState::initText() {
    titleText.setPosition(100, 25);
    titleText.setFont(font);
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("[Minesweeper]");

    numberOfBombsText.setPosition(175, 1400);
    numberOfBombsText.setFont(font);
    numberOfBombsText.setCharacterSize(30);
    numberOfBombsText.setFillColor(sf::Color::White);
    numberOfBombsText.setString("Number Of Bombs: " + std::to_string(board.getNumberOfBombs()));

    positionsOpenedText.setPosition(575, 1400);
    positionsOpenedText.setFont(font);
    positionsOpenedText.setCharacterSize(30);
    positionsOpenedText.setFillColor(sf::Color::White);
    positionsOpenedText.setString("Positions Opened: " + std::to_string(board.getPositionsOpened()) + "/" + std::to_string(GameBoard::MAX_BOARD_POSITIONS - board.getNumberOfBombs()));

    positionRemainingText.setPosition(975, 1400);
    positionRemainingText.setFont(font);
    positionRemainingText.setCharacterSize(30);
    positionRemainingText.setFillColor(sf::Color::White);
    positionRemainingText.setString("Positions Remaining: " + std::to_string(board.getPositionsRemaining()) + "/" + std::to_string(GameBoard::MAX_BOARD_POSITIONS - board.getNumberOfBombs()));

    gameOverText.setPosition(600, 25);
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(50);
}

///**
// * Initializes the font.
// */
//void GameState::initFont() {
//    if (!font.loadFromFile(FONT_PATH)) {
//        logger.error("Could not load font from file.", this);
//        exit(-1);
//    }
//    logger.info("Loaded font.", this);
//}

/**
 * Initializes the background.
 */
void GameState::initBackground() {
    background.setSize(sf::Vector2f{static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)});
    background.setFillColor(sf::Color::Black);
}

/**
 * Initializes all of the buttons and the button colors.
 */
void GameState::initButtons() {
    buttonColors["idle"] = sf::Color::Red;
    buttonColors["hover"] = sf::Color{50, 50, 50, 255};
    buttonColors["active"] = sf::Color::White;

    // Row 1
    buttons["Position1"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE,
            GAP_BETWEEN_BUTTON_AND_TOP,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position2"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            GAP_BETWEEN_BUTTON_AND_TOP,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position3"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            GAP_BETWEEN_BUTTON_AND_TOP,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position4"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            GAP_BETWEEN_BUTTON_AND_TOP,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position5"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            GAP_BETWEEN_BUTTON_AND_TOP,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position6"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            GAP_BETWEEN_BUTTON_AND_TOP,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    // Row 2
    buttons["Position7"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE,
            GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position8"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position9"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position10"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position11"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position12"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    // Row 3
    buttons["Position13"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position14"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position15"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position16"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position17"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position18"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    // Row 4
    buttons["Position19"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position20"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position21"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position22"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position23"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position24"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    // Row 5
    buttons["Position25"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position26"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position27"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position28"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position29"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position30"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    // Row 6
    buttons["Position31"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position32"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTONS,
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position33"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + (GAP_BETWEEN_BUTTONS*2),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position34"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + (GAP_BETWEEN_BUTTONS*3),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position35"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + (GAP_BETWEEN_BUTTONS*4),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };

    buttons["Position36"] = new Button {
            GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + (GAP_BETWEEN_BUTTONS*5),
            BUTTON_WIDTH,
            BUTTON_HEIGHT,
            &font,
            0,
            "",
            buttonColors["idle"],
            buttonColors["hover"],
            buttonColors["active"]
    };
}

/**
 * Initializes the grid.
 */
void GameState::initGrid() {
    // Vertical Grid Lines
    sf::RectangleShape line1;
    line1.setPosition((GAP_BETWEEN_BUTTON_AND_EDGE + BUTTON_WIDTH + GAP_BETWEEN_BUTTON_AND_GRID_LINE), GAP_BETWEEN_GRID_LINE_AND_TOP);
    line1.setSize(sf::Vector2f{GRID_LINE_WIDTH, GRID_LINE_HEIGHT});
    line1.setFillColor(sf::Color::White);

    sf::RectangleShape line2;
    line2.setPosition(GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*2) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + GAP_BETWEEN_BUTTONS, GAP_BETWEEN_GRID_LINE_AND_TOP);
    line2.setSize(sf::Vector2f{GRID_LINE_WIDTH, GRID_LINE_HEIGHT});
    line2.setFillColor(sf::Color::White);

    sf::RectangleShape line3;
    line3.setPosition(GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*3) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + (GAP_BETWEEN_BUTTONS*2), GAP_BETWEEN_GRID_LINE_AND_TOP);
    line3.setSize(sf::Vector2f{GRID_LINE_WIDTH, GRID_LINE_HEIGHT});
    line3.setFillColor(sf::Color::White);

    sf::RectangleShape line4;
    line4.setPosition(GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*4) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + (GAP_BETWEEN_BUTTONS*3), GAP_BETWEEN_GRID_LINE_AND_TOP);
    line4.setSize(sf::Vector2f{GRID_LINE_WIDTH, GRID_LINE_HEIGHT});
    line4.setFillColor(sf::Color::White);

    sf::RectangleShape line5;
    line5.setPosition(GAP_BETWEEN_BUTTON_AND_EDGE + (BUTTON_WIDTH*5) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + (GAP_BETWEEN_BUTTONS*4), GAP_BETWEEN_GRID_LINE_AND_TOP);
    line5.setSize(sf::Vector2f{GRID_LINE_WIDTH, GRID_LINE_HEIGHT});
    line5.setFillColor(sf::Color::White);

    // Horizontal Grid Lines
    sf::RectangleShape line6;
    line6.setPosition(GAP_BETWEEN_GRID_LINE_AND_EDGE, GAP_BETWEEN_BUTTON_AND_TOP + BUTTON_WIDTH + GAP_BETWEEN_BUTTON_AND_GRID_LINE );
    line6.setSize(sf::Vector2f{GRID_LINE_HEIGHT, GRID_LINE_WIDTH});
    line6.setFillColor(sf::Color::White);

    sf::RectangleShape line7;
    line7.setPosition(GAP_BETWEEN_GRID_LINE_AND_EDGE, GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*2) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + GAP_BETWEEN_BUTTONS);
    line7.setSize(sf::Vector2f{GRID_LINE_HEIGHT, GRID_LINE_WIDTH});
    line7.setFillColor(sf::Color::White);

    sf::RectangleShape line8;
    line8.setPosition(GAP_BETWEEN_GRID_LINE_AND_EDGE, GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*3) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + (GAP_BETWEEN_BUTTONS*2));
    line8.setSize(sf::Vector2f{GRID_LINE_HEIGHT, GRID_LINE_WIDTH});
    line8.setFillColor(sf::Color::White);

    sf::RectangleShape line9;
    line9.setPosition(GAP_BETWEEN_GRID_LINE_AND_EDGE, GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*4) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + (GAP_BETWEEN_BUTTONS*3));
    line9.setSize(sf::Vector2f{GRID_LINE_HEIGHT, GRID_LINE_WIDTH});
    line9.setFillColor(sf::Color::White);

    sf::RectangleShape line10;
    line10.setPosition(GAP_BETWEEN_GRID_LINE_AND_EDGE, GAP_BETWEEN_BUTTON_AND_TOP + (BUTTON_WIDTH*5) + GAP_BETWEEN_BUTTON_AND_GRID_LINE + (GAP_BETWEEN_BUTTONS*4));
    line10.setSize(sf::Vector2f{GRID_LINE_HEIGHT, GRID_LINE_WIDTH});
    line10.setFillColor(sf::Color::White);

    grid[0] = line1;
    grid[1] = line2;
    grid[2] = line3;
    grid[3] = line4;
    grid[4] = line5;

    grid[5] = line6;
    grid[6] = line7;
    grid[7] = line8;
    grid[8] = line9;
    grid[9] = line10;
}
