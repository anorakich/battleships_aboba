cmake_minimum_required(VERSION 3.20)
project(battleships)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

add_executable(battleships main.cpp src/menu.cpp menu.h constants.h src/game.cpp game.h src/settings.cpp settings.h
        src/field.cpp field.h customText.h src/customText.cpp ship.h src/player.cpp player.h)

target_link_libraries(battleships sfml-graphics sfml-audio sfml-window sfml-system)