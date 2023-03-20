cmake_minimum_required(VERSION 3.23)
project(MineSweeperGUI)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        src/core/Application.cpp
        src/core/Application.h

        src/core/states/State.cpp
        src/core/states/State.h
        src/core/states/MainMenuState.cpp
        src/core/states/MainMenuState.h
        src/core/states/GameState.cpp
        src/core/states/GameState.h
        src/core/states/HowToPlayMenuState.cpp
        src/core/states/HowToPlayMenuState.h

        src/core/characters/Player.cpp
        src/core/characters/Player.h

        src/utilities/logger/Color.cpp
        src/utilities/logger/Color.h
        src/utilities/logger/Formatter.cpp
        src/utilities/logger/Formatter.h
        src/utilities/logger/Logger.cpp
        src/utilities/logger/Logger.h
        src/utilities/logger/Outputter.cpp
        src/utilities/logger/Outputter.h
        src/utilities/logger/Record.cpp
        src/utilities/logger/Record.h
        src/utilities/logger/Time.cpp
        src/utilities/logger/Time.h

        src/utilities/input/Input.cpp
        src/utilities/input/Input.h

        src/ui/Button.cpp
        src/ui/Button.h

        src/gameElements/GameBoard.cpp
        src/gameElements/GameBoard.h)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED) # SFML

add_executable(MineSweeperGUI src/main.cpp ${SOURCE_FILES})

include_directories(/usr/local/include ${SFML_INCLUDE_DIRS})
target_link_libraries(MineSweeperGUI sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


# Catch2 Testing Framework
find_package(Catch2 3 REQUIRED)

set(TEST_FILES test/gameElements/GameBoardTest.cpp)
set(FILES_TO_TEST ${SOURCE_FILES})

add_executable(tests ${TEST_FILES} ${FILES_TO_TEST})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

