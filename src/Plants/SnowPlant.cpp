//
// Created by david on 27/07/2022.
//

#include "SnowPlant.h"
#define SNOW_PLANT_POWER 1
#define SHOOTER_PLANT_HEALTH 10
#define SNOW_PLANT_COST 7

void SnowPlant::shoot() {
    Bullet *b = new Bullet(SNOW_PLANT_POWER, true, (float)this->getX(), this->getY());
}

SnowPlant::SnowPlant(int x, int y) {
    this->setX(x);
    this->setY(y);
    this->setHp(SHOOTER_PLANT_HEALTH);
    this->setCost(SNOW_PLANT_COST);
}
