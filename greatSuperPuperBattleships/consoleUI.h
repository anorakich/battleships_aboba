//
// Created by nikita on 25.04.22.
//

#ifndef BATTLESHIPS_CONSOLEUI_H
#define BATTLESHIPS_CONSOLEUI_H

#include <iostream>
#include "cell.h"
#include "UI.h"
#include <string>

class ConsoleUI : public UI {
public:
    Position getPosition() override {
        std::cout<<"attack!!!"<<'\n';
        Position position;
        position.read();
        return position;
    }
    void waitForNextTurn() override {
        std::string input;
        while(input != "next") {
            std::cin>>input;
        }
    }
};

#endif //BATTLESHIPS_CONSOLEUI_H
