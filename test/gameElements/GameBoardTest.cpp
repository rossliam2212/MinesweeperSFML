//
// Created by Liam Ross on 20/03/2023.
//

#include <catch2/catch_test_macros.hpp>

//#include "../../src/core/states/GameState.h"
#include "../../src/gameElements/GameBoard.h"


TEST_CASE("GameBoard::handlePlayerMove(int position)") {
}

TEST_CASE("GameBoard::checkPositionForBomb(int position)") {
}

TEST_CASE("GameBoard::getGameMode() const") {
    GameBoard board{fiveBomb};

    REQUIRE(board.getGameMode() == fiveBomb);
    REQUIRE(board.getGameMode() != oneBomb);
    REQUIRE(board.getGameMode() != threeBomb);
    REQUIRE(board.getGameMode() != tenBomb);
    REQUIRE(board.getGameMode() != twentyBomb);
    REQUIRE(board.getGameMode() != thirtyFiveBomb);
}

TEST_CASE("GameBoard::getNumberOfBombs() const") {
    GameBoard board1{oneBomb};
    REQUIRE(board1.getNumberOfBombs() == 1);

    GameBoard board2{threeBomb};
    REQUIRE(board2.getNumberOfBombs() == 3);

    GameBoard board3{fiveBomb};
    REQUIRE(board3.getNumberOfBombs() == 5);

    GameBoard board4{tenBomb};
    REQUIRE(board4.getNumberOfBombs() == 10);

    GameBoard board5{twentyBomb};
    REQUIRE(board5.getNumberOfBombs() == 20);

    GameBoard board6{thirtyFiveBomb};
    REQUIRE(board6.getNumberOfBombs() == 35);
}

TEST_CASE("GameBoard::getPositionsRemaining() const") {
    // GameMode = oneBomb
    GameBoard board1{oneBomb};
    int positionsRemaining{GameBoard::MAX_BOARD_POSITIONS - 1};
    REQUIRE(board1.getPositionsRemaining() == positionsRemaining);

    // GameMode = threeBomb
    GameBoard board2{threeBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 3;
    REQUIRE(board2.getPositionsRemaining() == positionsRemaining);

    // GameMode = fiveBomb
    GameBoard board3{fiveBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 5;
    REQUIRE(board3.getPositionsRemaining() == positionsRemaining);

    // GameMode = tenBomb
    GameBoard board4{tenBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 10;
    REQUIRE(board4.getPositionsRemaining() == positionsRemaining);

    // GameMode = twentyBomb
    GameBoard board5{twentyBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 20;
    REQUIRE(board5.getPositionsRemaining() == positionsRemaining);

    // GameMode = thirtyFiveBomb
    GameBoard board6{thirtyFiveBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 35;
    REQUIRE(board6.getPositionsRemaining() == positionsRemaining);


    // GameMode = onebomb
    // One position opened
    board1.handlePlayerMove(1);
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 2;
    REQUIRE(board1.getPositionsRemaining() == positionsRemaining);
}

TEST_CASE("GameBoard::getPositionsOpened() const") {
    GameBoard board{oneBomb};

    // Zero positions opened
    REQUIRE(board.getPositionsOpened() == 0);

    // One position opened
    board.handlePlayerMove(5);
    REQUIRE(board.getPositionsOpened() == 1);

    // Two positions opened
    board.handlePlayerMove(10);
    REQUIRE(board.getPositionsOpened() == 2);
}
