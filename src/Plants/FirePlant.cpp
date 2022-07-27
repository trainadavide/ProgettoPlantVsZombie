//
// Created by david on 27/07/2022.
//

#include "FirePlant.h"
#define FIRE_PLANT_POWER 2

void FirePlant::shoot() {
    Bullet *b = new Bullet(FIRE_PLANT_POWER, false, (float)this->getX(), this->getY());
}