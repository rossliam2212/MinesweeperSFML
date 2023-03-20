//
// Created by Liam Ross on 20/03/2023.
//

#include <catch2/catch_test_macros.hpp>

#include "../../src/core/states/GameState.h"
#include "../../src/gameElements/GameBoard.h"


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
    GameBoard board1{oneBomb};
    int positionsRemaining{GameBoard::MAX_BOARD_POSITIONS - 1};
    REQUIRE(board1.getPositionsRemaining() == positionsRemaining);

    GameBoard board2{threeBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 3;
    REQUIRE(board2.getPositionsRemaining() == positionsRemaining);

    GameBoard board3{fiveBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 5;
    REQUIRE(board3.getPositionsRemaining() == positionsRemaining);

    GameBoard board4{tenBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 10;
    REQUIRE(board4.getPositionsRemaining() == positionsRemaining);

    GameBoard board5{twentyBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 20;
    REQUIRE(board5.getPositionsRemaining() == positionsRemaining);

    GameBoard board6{thirtyFiveBomb};
    positionsRemaining = GameBoard::MAX_BOARD_POSITIONS - 35;
    REQUIRE(board6.getPositionsRemaining() == positionsRemaining);
}

TEST_CASE("GameBoard::getPositionsOpened() const") {
}