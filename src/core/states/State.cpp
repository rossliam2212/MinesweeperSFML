//
// Created by Liam Ross on 16/03/2023.
//

#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states) noexcept
    : window{window},
      states{states},
      end{false},
      logger{"logs"} {
    input::Input::Mouse::init(window);
}

void State::updateMousePositions() {
    mousePosScreen = input::Input::Mouse::getPosition();
    mousePosWindow = input::Input::Mouse::getRelativePosition();
    mousePosView = input::Input::Mouse::getRelativeCoords();
}

void State::endState() {
    end = true;
}

const bool& State::getEnd() const {
    return end;
}

void State::delayForMilliSeconds(int milliseconds) {
    if (milliseconds <= 0) {
        logger.error("Cannot delay for 0 or negative milliseconds!", this);
        return;
    }
    std::chrono::milliseconds mills{std::chrono::milliseconds{milliseconds}};
    std::this_thread::sleep_for(mills);
}