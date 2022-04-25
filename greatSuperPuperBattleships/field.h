//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_FIELD_H
#define BATTLESHIPS_FIELD_H

#include <vector>
#include "cell.h"
class Field {
private:
    Cell cell;
    std::vector<std::vector<Cell*>> field;
public:
    Field() {
        field = std::vector<std::vector<Cell*>> (10,std::vector<Cell*> (10, &cell));
    }
    const Cell& at(int i, int j) const {return *field[i][j];}
};


#endif //BATTLESHIPS_FIELD_H
