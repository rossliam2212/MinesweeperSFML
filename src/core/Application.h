//
// Created by Liam Ross on 16/03/2023.
//

#ifndef MINESWEEPERGUI_APPLICATION_H
#define MINESWEEPERGUI_APPLICATION_H


#include "states/MainMenuState.h"

class Application {
private:
    static constexpr const int WINDOW_WIDTH{1500};
    static constexpr const int WINDOW_HEIGHT{1500};

    sf::RenderWindow* window;
    sf::Event event;

    std::stack<State*> states;
    logger::Logger logger;

public:
    Application() noexcept;
    ~Application();

    void run();

private:
    Application(const Application& other);
    Application& operator=(const Application& other);

    void update();
    void updateEvents();
    void render();

    void initWindow();
    void initStates();

    void endApplication();
};


#endif //MINESWEEPERGUI_APPLICATION_H
