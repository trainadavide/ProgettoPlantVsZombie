//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_NUT_H
#define PLANTVSZOMBIE_NUT_H

#include "Plant.h"

#define NUT_HEALTH 20
#define NUT_COST 2

class Nut : public Plant{
    public:
        Nut(int x, int y):Plant(){
            this->setX(x);
            this->setY(y);
            this->setHp(NUT_HEALTH);
            this->setCost(NUT_COST);
        }
};


#endif //PLANTVSZOMBIE_NUT_H
