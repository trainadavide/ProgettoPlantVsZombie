//
// Created by david on 27/07/2022.
//

#include "GreenPlant.h"
#define GREEN_PLANT_POWER 1

void GreenPlant::shoot() {
    Bullet *b = new Bullet(GREEN_PLANT_POWER, false, (float)this->getX(), this->getY());
}
