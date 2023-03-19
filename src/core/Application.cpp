//
// Created by Liam Ross on 16/03/2023.
//

#include "Application.h"

Application::Application() noexcept
        : window{nullptr},
          event{},
          states{},
          logger{"logs"} {
    logger.start("Application starting.", this);
    initWindow();
    initStates();
}

Application::~Application() {
    delete window;

    while (!states.empty()) {
        delete states.top();
        states.pop();
    }
}

void Application::run() {
    while (window->isOpen()) {
        update();
        render();
    }
}

void Application::update() {
    updateEvents();

    // Handles the states
    if (!states.empty()) {
        states.top()->update();

        // If the current state is over
        if (states.top()->getEnd()) {
//                states.top()->endState(); // Print state ended message
            delete states.top(); // Free the pointer
            states.pop(); // Remove the state from the stack
        }
    } else
        endApplication();
}

void Application::updateEvents() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            endApplication();
        }
    }
}

void Application::render() {
    window->clear();

    if (!states.empty())
        states.top()->render(window);

    window->display();
}

void Application::initWindow() {
    logger.info("Window initialized.", this);
    window = new sf::RenderWindow{sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Minesweeper", sf::Style::Titlebar | sf::Style::Close};
}

void Application::initStates() {
    logger.info("Starting MainMenuState.", this);
    states.push(new MainMenuState{window, &states});
}

void Application::endApplication() {
    window->close();
    logger.info("Logs written to: '" + logger.getWhereLogged() + "'", this);
    logger.end("Application ended.", this);
    logger.info("==================================================================================", this);
}
