//
// Created by nikita on 24.04.22.
//

#ifndef BATTLESHIPS_FIELD_H
#define BATTLESHIPS_FIELD_H

#include <vector>
#include "cell.h"
class Field {
public:
    explicit Field(size_t _sz);
private:
    size_t sz;
    std::vector<std::vector<Cell*>> field;
};


#endif //BATTLESHIPS_FIELD_H
