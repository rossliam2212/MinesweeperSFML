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
#include <sstream>
#include <chrono>
#include <thread>

#include "../../utilities/logger/Logger.h"
#include "../../utilities/input/Input.h"

class State {
protected:
    static const std::string FONT_PATH;

    sf::RenderWindow* window;
    std::stack<State*>* states;
    bool end;

    sf::Font font;

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

private:
    void initFont();
};


#endif //MINESWEEPERGUI_STATE_H
