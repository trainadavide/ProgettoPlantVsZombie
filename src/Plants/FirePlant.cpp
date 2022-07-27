//
// Created by david on 27/07/2022.
//

#include "FirePlant.h"
#define FIRE_PLANT_POWER 2
#define SHOOTER_PLANT_HEALTH 10
#define FIRE_PLANT_COST 7

void FirePlant::shoot() {
    Bullet *b = new Bullet(FIRE_PLANT_POWER, false, (float)this->getX(), this->getY());
}

FirePlant::FirePlant(int x, int y) {
    this->setX(x);
    this->setY(y);
    this->setHp(SHOOTER_PLANT_HEALTH);
    this->setCost(FIRE_PLANT_COST);
}

