//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_FIELD_H
#define BATTLESHIPS_FIELD_H

#include <vector>
#include "cell.h"
class Field {
private:
    std::vector<std::vector<Cell*>> field;
};


#endif //BATTLESHIPS_FIELD_H
