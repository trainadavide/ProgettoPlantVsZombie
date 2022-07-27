//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_SHOOTERPLANT_H
#define PLANTVSZOMBIE_SHOOTERPLANT_H
#include "Plant.h"
#include "../Bullet.h"

class ShooterPlant : public Plant{
public:
    virtual void shoot();
};


#endif //PLANTVSZOMBIE_SHOOTERPLANT_H
