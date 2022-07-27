//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_MAP_H
#define PLANTVSZOMBIE_MAP_H
#include "Plants/Plant.h"
#define LENGTH_GRID 9
#define WIDTH_GRID 5

class Map {
private:
    Plant* grid [WIDTH_GRID][LENGTH_GRID];
    bool lawnmower [WIDTH_GRID];
public:
    void setPlant(Plant* p,int x,int y);
    bool isEmpty(int x, int y);
};


#endif //PLANTVSZOMBIE_MAP_H
