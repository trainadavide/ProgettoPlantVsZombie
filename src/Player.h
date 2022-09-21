//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_PLAYER_H
#define PLANTVSZOMBIE_PLAYER_H

#include "Map.h"

class Player {
private:
    int energy;
    int time;
    int selectedPlant;

public:
    Player(int energy);
    void increaseEnergy();
    void select(int selected);
    void place(Map m, int x, int y);
};


#endif //PLANTVSZOMBIE_PLAYER_H
