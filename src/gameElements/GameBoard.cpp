//
// Created by Liam Ross on 16/03/2023.
//

#include "GameBoard.h"

const std::array<std::vector<int>, 36> GameBoard::positionSurroundings {
        std::vector{2, 7, 8},
        std::vector{1, 3, 7, 8, 9},
        std::vector{2, 4, 8, 9, 10},
        std::vector{3, 5, 9, 10, 11},
        std::vector{4, 6, 10, 11, 12},
        std::vector{5, 11, 12},
        std::vector{1, 2, 8, 13, 14},
        std::vector{1, 2, 3, 7, 9, 13, 14, 15},
        std::vector{2, 3, 4, 8, 10, 14, 15, 16},
        std::vector{3, 4, 5, 9, 11, 15, 16, 17},
        std::vector{4, 5, 6, 10, 12, 16, 17, 18},
        std::vector{5, 6, 11, 17, 18},
        std::vector{7, 8, 14, 19, 20},
        std::vector{7, 8, 9, 13, 15, 19, 20, 21},
        std::vector{8, 9, 10, 14, 16, 20, 21, 22},
        std::vector{9, 10, 11, 15, 17, 21, 22, 23},
        std::vector{10, 11, 12, 16, 18, 22, 23, 24},
        std::vector{11, 12, 17, 23, 24},
        std::vector{13, 14, 20, 25, 26},
        std::vector{13, 14, 15, 19, 21, 25, 26, 27},
        std::vector{14, 15, 16, 20, 22, 26, 27, 28},
        std::vector{15, 16, 17, 21, 23, 27, 28, 29},
        std::vector{16, 17, 18, 22, 24, 28, 29, 30},
        std::vector{17, 18, 23, 29, 30},
        std::vector{19, 20, 26, 31, 32},
        std::vector{19, 20, 21, 25, 27, 31, 32, 33},
        std::vector{20, 21, 22, 26, 28, 32, 33, 34},
        std::vector{21, 22, 23, 27, 29, 33, 34, 35},
        std::vector{22, 23, 24, 28, 30, 34, 35, 36},
        std::vector{23, 24, 29, 35, 36},
        std::vector{25, 26, 32},
        std::vector{25, 26, 27, 31, 33},
        std::vector{26, 27, 28, 32, 34},
        std::vector{27, 28, 29, 33, 35},
        std::vector{28, 29, 30, 34, 36},
        std::vector{29, 30, 35},
};

GameBoard::GameBoard(int numberOfBombs) noexcept
    : numberOfBombs{numberOfBombs},
      positionsOpened{},
      positionsRemaining{MAX_BOARD_POSITIONS - numberOfBombs},
      loss{false},
      win{false},
      logger{"logs"} {
    logger.info("Number of bombs on board: " + std::to_string(numberOfBombs) + ".", this);

    initTextures();
    initSprites();
    initPositionsForPiecesOnBoard();

    placeBombsOnBoard();
}

void GameBoard::update() {

}

void GameBoard::render(sf::RenderWindow* window) {
    if (loss) {
        for (const auto& bomb : bombsOnBoard)
            window->draw(bomb.second);
    }
    for (const auto& number : numbersOnBoard)
        window->draw(number.second);
}

void GameBoard::handlePlayerMove(int position) {
    if (!checkPositionForBomb(position)) {
        int bombsTouchingPosition{calculateNumberOfBombsTouchingPosition(position)};
        playerPositions.emplace_back(position);
        logger.info("Position " + std::to_string(position) + " clear => " + std::to_string(bombsTouchingPosition) + " bomb(s) touching it.", this);

        positionsRemaining--;
        positionsOpened++;

        // Add sprite to board
        addToBoard(position, bombsTouchingPosition);

        // Checking if the player has won
        if (positionsOpened == (36 - numberOfBombs)) {
            // Handle win
            win = true;
        }
    } else {
        // Game Over
        logger.info("Bomb found in position " + std::to_string(position) + ".", this);
        loss = true;
    }
}

void GameBoard::addToBoard(int position, int numberOfBombsTouching) {
    sf::Sprite s;

    switch (numberOfBombsTouching) {
        case 0:
            s = zeroSprite;
            break;
        case 1:
            s = oneSprite;
            break;
        case 2:
            s = twoSprite;
            break;
        case 3:
            s = threeSprite;
            break;
        case 4:
            s = fourSprite;
            break;
        case 5:
            s = fiveSprite;
            break;
        case 6:
            s = sixSprite;
            break;
        case 7:
            s = sevenSprite;
            break;
        case 8:
            s = eightSprite;
            break;
    }

    playerPositions.emplace_back(position);
    numbersOnBoard[position] = s;
    numbersOnBoard[position].setPosition(positionOfPiecesOnBoard[position]);
}

/**
 * Checks a position to see if it contains a bomb.
 * @param position The position to be checked.
 * @return True if the position contains a bomb, False otherwise.
 */
bool GameBoard::checkPositionForBomb(int position) {
    if (std::find(bombPositions.begin(), bombPositions.end(), position) != bombPositions.end())
        return true;
    return false;
}

/**
 * Calculates the number of bombs that are touching a position.
 * @param position The position to be checked.
 * @return The number of bombs that touch the position.
 */
int GameBoard::calculateNumberOfBombsTouchingPosition(int position) {
    int bombsTouchingPosition{};
    auto positionsToCheck{positionSurroundings.at(position-1)};

    for (int i = 0; i < bombPositions.size(); ++i) {
        for (int j = 0; j < positionsToCheck.size(); ++j) {
            if (bombPositions.at(i) == positionsToCheck.at(j))
                bombsTouchingPosition++;
        }
    }
    return bombsTouchingPosition;
}

/**
 * Randomly places all the bombs in positions on the board.
 */
void GameBoard::placeBombsOnBoard() {
    for (int i = 0; i < numberOfBombs; ++i) {
        int randomPosition = getRandomNumber(1, 36);

        while (std::find(bombPositions.begin(), bombPositions.end(), randomPosition) != bombPositions.end())
            randomPosition = getRandomNumber(1, 36);

        bombPositions.emplace_back(randomPosition);
        bombsOnBoard[randomPosition] = bombSprite;
        bombsOnBoard[randomPosition].setPosition(positionOfPiecesOnBoard[randomPosition]);
    }
}

/**
 * Generates a random integer.
 * @param min - The minimum value - included.
 * @param max - The maximum value - included.
 * @return A random integer between the min and max values.
 */
int GameBoard::getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, max);

    return dist(mt);
}

/**
 * Initializes all the textures.
 */
void GameBoard::initTextures() {
    if (!bombTexture.loadFromFile("../assets/images/bomb.png")) {
        logger.error("Failed to load 'bomb' texture", this);
        exit(-1);
    }
    logger.info("'bomb' texture loaded.", this);

    if (!zeroTexture.loadFromFile("../assets/images/0.png")) {
        logger.error("Failed to load '0' texture", this);
        exit(-1);
    }
    logger.info("'0' texture loaded.", this);

    if (!oneTexture.loadFromFile("../assets/images/1.png")) {
        logger.error("Failed to load '1' texture", this);
        exit(-1);
    }
    logger.info("'1' texture loaded.", this);

    if (!twoTexture.loadFromFile("../assets/images/2.png")) {
        logger.error("Failed to load '2' texture", this);
        exit(-1);
    }
    logger.info("'2' texture loaded.", this);

    if (!threeTexture.loadFromFile("../assets/images/3.png")) {
        logger.error("Failed to load '3' texture", this);
        exit(-1);
    }
    logger.info("'3' texture loaded.", this);

    if (!fourTexture.loadFromFile("../assets/images/4.png")) {
        logger.error("Failed to load '4' texture", this);
        exit(-1);
    }
    logger.info("'4' texture loaded.", this);

    if (!fiveTexture.loadFromFile("../assets/images/5.png")) {
        logger.error("Failed to load '5' texture", this);
        exit(-1);
    }
    logger.info("'5' texture loaded.", this);

    if (!sixTexture.loadFromFile("../assets/images/6.png")) {
        logger.error("Failed to load '6' texture", this);
        exit(-1);
    }
    logger.info("'6' texture loaded.", this);

    if (!sevenTexture.loadFromFile("../assets/images/7.png")) {
        logger.error("Failed to load '7' texture", this);
        exit(-1);
    }
    logger.info("'7' texture loaded.", this);

    if (!eightTexture.loadFromFile("../assets/images/8.png")) {
        logger.error("Failed to load '8' texture", this);
        exit(-1);
    }
    logger.info("'8' texture loaded.", this);
}

/**
 * Initializes all the sprites.
 */
void GameBoard::initSprites() {
    bombSprite.setTexture(bombTexture);
    bombSprite.setScale(0.2f, 0.2f);
    sf::FloatRect bounds = bombSprite.getLocalBounds();
    bombSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    zeroSprite.setTexture(zeroTexture);
    zeroSprite.setScale(0.2f, 0.2f);
    bounds = zeroSprite.getLocalBounds();
    zeroSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    oneSprite.setTexture(oneTexture);
    oneSprite.setScale(0.2f, 0.2f);
    bounds = oneSprite.getLocalBounds();
    oneSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    twoSprite.setTexture(twoTexture);
    twoSprite.setScale(0.2f, 0.2f);
    bounds = twoSprite.getLocalBounds();
    twoSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    threeSprite.setTexture(threeTexture);
    threeSprite.setScale(0.2f, 0.2f);
    bounds = threeSprite.getLocalBounds();
    threeSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    fourSprite.setTexture(fourTexture);
    fourSprite.setScale(0.2f, 0.2f);
    bounds = fourSprite.getLocalBounds();
    fourSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    fiveSprite.setTexture(fiveTexture);
    fiveSprite.setScale(0.2f, 0.2f);
    bounds = fiveSprite.getLocalBounds();
    fiveSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    sixSprite.setTexture(sixTexture);
    sixSprite.setScale(0.2f, 0.2f);
    bounds = sixSprite.getLocalBounds();
    sixSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    sevenSprite.setTexture(sevenTexture);
    sevenSprite.setScale(0.2f, 0.2f);
    bounds = sevenSprite.getLocalBounds();
    sevenSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);

    eightSprite.setTexture(eightTexture);
    eightSprite.setScale(0.2f, 0.2f);
    bounds = eightSprite.getLocalBounds();
    eightSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

/**
 * Initializes the positions to place each of the symbols on the board.
 */
void GameBoard::initPositionsForPiecesOnBoard() {
    positionOfPiecesOnBoard[1] = sf::Vector2f{250, 225};
    positionOfPiecesOnBoard[2] = sf::Vector2f{450, 225};
    positionOfPiecesOnBoard[3] = sf::Vector2f{650, 225};
    positionOfPiecesOnBoard[4] = sf::Vector2f{850, 225};
    positionOfPiecesOnBoard[5] = sf::Vector2f{1050, 225};
    positionOfPiecesOnBoard[6] = sf::Vector2f{1250, 225};

    positionOfPiecesOnBoard[7] = sf::Vector2f{250, 425};
    positionOfPiecesOnBoard[8] = sf::Vector2f{450, 425};
    positionOfPiecesOnBoard[9] = sf::Vector2f{650, 425};
    positionOfPiecesOnBoard[10] = sf::Vector2f{850, 425};
    positionOfPiecesOnBoard[11] = sf::Vector2f{1050, 425};
    positionOfPiecesOnBoard[12] = sf::Vector2f{1250, 425};

    positionOfPiecesOnBoard[13] = sf::Vector2f{250, 625};
    positionOfPiecesOnBoard[14] = sf::Vector2f{450, 625};
    positionOfPiecesOnBoard[15] = sf::Vector2f{650, 625};
    positionOfPiecesOnBoard[16] = sf::Vector2f{850, 625};
    positionOfPiecesOnBoard[17] = sf::Vector2f{1050, 625};
    positionOfPiecesOnBoard[18] = sf::Vector2f{1250, 625};

    positionOfPiecesOnBoard[19] = sf::Vector2f{250, 825};
    positionOfPiecesOnBoard[20] = sf::Vector2f{450, 825};
    positionOfPiecesOnBoard[21] = sf::Vector2f{650, 825};
    positionOfPiecesOnBoard[22] = sf::Vector2f{850, 825};
    positionOfPiecesOnBoard[23] = sf::Vector2f{1050, 825};
    positionOfPiecesOnBoard[24] = sf::Vector2f{1250, 825};

    positionOfPiecesOnBoard[25] = sf::Vector2f{250, 1025};
    positionOfPiecesOnBoard[26] = sf::Vector2f{450, 1025};
    positionOfPiecesOnBoard[27] = sf::Vector2f{650, 1025};
    positionOfPiecesOnBoard[28] = sf::Vector2f{860, 1025};
    positionOfPiecesOnBoard[29] = sf::Vector2f{1050, 1025};
    positionOfPiecesOnBoard[30] = sf::Vector2f{1250, 1025};

    positionOfPiecesOnBoard[31] = sf::Vector2f{250, 1225};
    positionOfPiecesOnBoard[32] = sf::Vector2f{450, 1225};
    positionOfPiecesOnBoard[33] = sf::Vector2f{650, 1225};
    positionOfPiecesOnBoard[34] = sf::Vector2f{860, 1225};
    positionOfPiecesOnBoard[35] = sf::Vector2f{1050, 1225};
    positionOfPiecesOnBoard[36] = sf::Vector2f{1250, 1225};
}

int GameBoard::getNumberOfBombs() const {
    return numberOfBombs;
}

int GameBoard::getPositionsRemaining() const {
    return positionsRemaining;
}

int GameBoard::getPositionsOpened() const {
    return positionsOpened;
}

bool GameBoard::checkIfWon() const {
    return win;
}

bool GameBoard::checkIfLoss() const {
    return loss;
}