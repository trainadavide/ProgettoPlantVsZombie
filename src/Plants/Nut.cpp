//
// Created by david on 27/07/2022.
//

#include "Nut.h"
Nut::Nut(int x, int y):Plant(){
    this->setX(x);
    this->setY(y);
    this->setHp(NUT_HEALTH);
    this->setCost(NUT_COST);
}