//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_SUNFLOWER_H
#define PLANTVSZOMBIE_SUNFLOWER_H
#include "Plant.h"
#include "../Player.h"

class Sunflower : public Plant{
public:
    Sunflower(int x, int y);
    static void makeEnergy(Player p);


};


#endif //PLANTVSZOMBIE_SUNFLOWER_H
