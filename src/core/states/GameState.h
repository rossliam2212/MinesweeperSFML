//
// Created by Liam Ross on 16/03/2023.
//

#ifndef MINESWEEPERGUI_GAMESTATE_H
#define MINESWEEPERGUI_GAMESTATE_H

#include "State.h"
#include "../characters/Player.h"
#include "../../gameElements/GameBoard.h"
#include "../../ui/Button.h"

class GameState : public State {
private:
    // Constants
    static constexpr const int BUTTON_WIDTH{150};
    static constexpr const int BUTTON_HEIGHT{150};
    static constexpr const int GAP_BETWEEN_BUTTON_AND_TOP{150};
    static constexpr const int GAP_BETWEEN_BUTTON_AND_EDGE{175};
    static constexpr const int GAP_BETWEEN_BUTTON_AND_GRID_LINE{20};
    static constexpr const int GAP_BETWEEN_BUTTONS{50};

    static constexpr const int GRID_LINE_WIDTH{10};
    static constexpr const int GRID_LINE_HEIGHT{1200};
    static constexpr const int GAP_BETWEEN_GRID_LINE_AND_EDGE{150};
    static constexpr const int GAP_BETWEEN_GRID_LINE_AND_TOP{125};

//    Player* player;

    GameBoard board;
    bool gameOver;

    // UI
    sf::Text titleText;
    sf::Font font;
    sf::RectangleShape background;

    sf::Text numberOfBombsText;
    sf::Text positionsOpenedText;
    sf::Text positionRemainingText;
    sf::Text gameOverText;

    std::array<sf::RectangleShape, 10> grid;
    std::map<std::string, Button*> buttons;
    std::map<std::string, sf::Color> buttonColors;

public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states, GameMode gameMode) noexcept;
    ~GameState() override;

    void update() override;
    void render(sf::RenderWindow* window) override;

private:
    void checkGameOver();
    void handleMove(int position);

    void updateText();
    void updateButtons();
    void hideAllButtons();

    void renderButtons(sf::RenderWindow* window);

    void initText();
    void initFont();
    void initBackground();
    void initButtons();
    void initGrid();
};


#endif //MINESWEEPERGUI_GAMESTATE_H
