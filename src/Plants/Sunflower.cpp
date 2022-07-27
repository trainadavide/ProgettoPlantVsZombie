//
// Created by david on 27/07/2022.
//

#include "Sunflower.h"
#define SUNFLOWER_HEALTH 10
#define SUNFLOWER_COST 2

Sunflower::Sunflower(int x, int y):Plant(){
    this->setX(x);
    this->setY(y);
    this->setHp(SUNFLOWER_HEALTH);
    this->setCost(SUNFLOWER_COST);
}

void Sunflower::makeEnergy(Player p) {
    p.increaseEnergy();
}
