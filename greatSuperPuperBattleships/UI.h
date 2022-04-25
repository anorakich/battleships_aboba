//
// Created by nikita on 25.04.22.
//

#ifndef BATTLESHIPS_UI_H
#define BATTLESHIPS_UI_H
#include "cell.h"
#include "field.h"
class UI{
    virtual Position getAttackPosition() = 0;
    virtual void displayField(const Field& field) = 0;
    virtual std::pair<Position,Position> getPositionToSetShip(const Field& field) = 0;
    virtual ~UI() = default;

};
#endif //BATTLESHIPS_UI_H
