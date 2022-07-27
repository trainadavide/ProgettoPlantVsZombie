//
// Created by david on 27/07/2022.
//

#include "GreenPlant.h"
#define GREEN_PLANT_POWER 1
#define SHOOTER_PLANT_HEALTH 10
#define GREEN_PLANT_COST 4

void GreenPlant::shoot() {
    Bullet *b = new Bullet(GREEN_PLANT_POWER, false, (float)this->getX(), this->getY());
}

GreenPlant::GreenPlant(int x, int y) {
    this->setX(x);
    this->setY(y);
    this->setHp(SHOOTER_PLANT_HEALTH);
    this->setCost(GREEN_PLANT_COST);
}
