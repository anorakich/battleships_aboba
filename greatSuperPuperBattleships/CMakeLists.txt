cmake_minimum_required(VERSION 3.20)
project(battleships)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

add_executable(battleships main.cpp src/menu.cpp menu.h src/game.cpp game.h settings.h
        customText.h src/customText.cpp constants.h src/cell.cpp cell.h src/ship.cpp ship.h src/player.cpp player.h src/field.cpp field.h UI.h GraphicUI.h)

target_link_libraries(battleships sfml-graphics sfml-audio sfml-window sfml-system X11)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)