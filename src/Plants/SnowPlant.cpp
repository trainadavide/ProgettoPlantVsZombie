//
// Created by david on 27/07/2022.
//

#include "SnowPlant.h"
#define SNOW_PLANT_POWER 1

void SnowPlant::shoot() {
    Bullet *b = new Bullet(SNOW_PLANT_POWER, true, (float)this->getX(), this->getY());
}
