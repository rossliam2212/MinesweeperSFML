//
// Created by Liam Ross on 16/03/2023.
//

#include "State.h"

const std::string State::FONT_PATH{"../assets/fonts/Pixellari.ttf"};

State::State(sf::RenderWindow* window, std::stack<State*>* states) noexcept
    : window{window},
      states{states},
      end{false},
      logger{"logs"} {
    input::Input::Mouse::init(window);
    initFont();
}

/**
 * Updates the current position of the mouse.
 */
void State::updateMousePositions() {
    mousePosScreen = input::Input::Mouse::getPosition();
    mousePosWindow = input::Input::Mouse::getRelativePosition();
    mousePosView = input::Input::Mouse::getRelativeCoords();
}

/**
 * Ends the current state.
 */
void State::endState() {
    end = true;
}

/**
 * Gets whether the current state has ended or not.
 * @return True if the current state has ended, False otherwise.
 */
const bool& State::getEnd() const {
    return end;
}

/**
 * Delays for a certain amount of milliseconds.
 * @param milliseconds The amount of time to delay for.
 */
void State::delayForMilliSeconds(int milliseconds) {
    if (milliseconds <= 0) {
        logger.error("Cannot delay for 0 or negative milliseconds!", this);
        return;
    }
    std::chrono::milliseconds mills{std::chrono::milliseconds{milliseconds}};
    std::this_thread::sleep_for(mills);
}

/**
 * Initializes the font.
 */
void State::initFont() {
    if (!font.loadFromFile(FONT_PATH)) {
        logger.error("Could not load font from file.", this);
        return;
    }
    logger.info("Font loaded from: " + FONT_PATH, this);
}