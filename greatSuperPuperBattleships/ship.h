//
// Created by nikita on 16.04.22.
//

#ifndef BATTLESHIPS_SHIP_H
#define BATTLESHIPS_SHIP_H
#include <vector>
struct block {
    size_t pos_x;
    size_t pos_y;
    bool is_dead;
};
class Ship {
private:
    std::vector<block> shipBlocksPosition;
public:
    std::vector<block> getBlocksPosition() const {return shipBlocksPosition;}
    size_t getShipSize() const {return shipBlocksPosition.size();}
};
#endif //BATTLESHIPS_SHIP_H
