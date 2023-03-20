//
// Created by Liam Ross on 16/03/2023.
//

#ifndef MINESWEEPERGUI_GAMEBOARD_H
#define MINESWEEPERGUI_GAMEBOARD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <random>

#include "../utilities/logger/Logger.h"


enum GameMode {
    oneBomb,
    threeBomb,
    fiveBomb,
    tenBomb,
    twentyBomb,
    thirtyFiveBomb
};

class GameBoard {
public:
    static constexpr const int MAX_BOARD_POSITIONS{36};
private:
    GameMode mode;
    int numberOfBombs;
    std::vector<int> playerPositions;
    std::vector<int> bombPositions;

    bool loss;
    bool win;

    int positionsOpened;
    int positionsRemaining;
    static const std::array<std::vector<int>, 36> positionSurroundings;

    std::map<int, sf::Sprite> bombsOnBoard;
    std::map<int, sf::Sprite> numbersOnBoard;
    std::map<int, sf::Vector2f> positionOfPiecesOnBoard;

    logger::Logger logger;

    // Textures
    sf::Texture bombTexture;
    sf::Texture zeroTexture;
    sf::Texture oneTexture;
    sf::Texture twoTexture;
    sf::Texture threeTexture;
    sf::Texture fourTexture;
    sf::Texture fiveTexture;
    sf::Texture sixTexture;
    sf::Texture sevenTexture;
    sf::Texture eightTexture;

    // Sprites
    sf::Sprite bombSprite;
    sf::Sprite zeroSprite;
    sf::Sprite oneSprite;
    sf::Sprite twoSprite;
    sf::Sprite threeSprite;
    sf::Sprite fourSprite;
    sf::Sprite fiveSprite;
    sf::Sprite sixSprite;
    sf::Sprite sevenSprite;
    sf::Sprite eightSprite;

public:
    GameBoard(GameMode gameMode) noexcept;

    void update();
    void render(sf::RenderWindow* window);

    void handlePlayerMove(int position);

    GameMode getGameMode() const;
    int getNumberOfBombs() const;
    int getPositionsRemaining() const;
    int getPositionsOpened() const;
    bool checkIfWon() const;
    bool checkIfLoss() const;

private:
    bool checkPositionForBomb(int position);
    int calculateNumberOfBombsTouchingPosition(int position);
    void addToBoard(int position, int numberOfBombsTouching);

    void placeBombsOnBoard();
    static int getRandomNumber(int min, int max);

    void initTextures();
    void initSprites();
    void initPositionsForPiecesOnBoard();
};


#endif //MINESWEEPERGUI_GAMEBOARD_H
