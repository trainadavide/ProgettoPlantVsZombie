//
// Created by david on 27/07/2022.
//

#include <cstddef>
#include "Map.h"

void Map::setPlant(Plant* p, int x, int y) {
    this->grid[y][x]=p;
}

bool Map::isEmpty(int x, int y) {
    if(this->grid[y][x]==NULL)
        return true;
    return false;
}
