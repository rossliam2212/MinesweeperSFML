//
// Created by Liam Ross on 16/03/2023.
//

#ifndef MINESWEEPERGUI_STATE_H
#define MINESWEEPERGUI_STATE_H

#include <SFML/Graphics.hpp>
#include <stack>
#include <array>
#include <map>
#include <string>
#include <chrono>
#include <thread>

#include "../../utilities/logger/Logger.h"
#include "../../utilities/input/Input.h"

class State {
protected:
    static constexpr const char* FONT_PATH{"../assets/fonts/Pixellari.ttf"};

    sf::RenderWindow* window;
    std::stack<State*>* states;
    bool end;

    sf::Vector2f mousePosWindow;
    sf::Vector2f mousePosScreen;
    sf::Vector2f mousePosView;
    logger::Logger logger;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states) noexcept;
    virtual ~State() = default;

    virtual void update() = 0;
    virtual void render(sf::RenderWindow* window) = 0;

    virtual void updateMousePositions();

    void endState();
    const bool& getEnd() const;

protected:
    void delayForMilliSeconds(int milliseconds);
};


#endif //MINESWEEPERGUI_STATE_H
