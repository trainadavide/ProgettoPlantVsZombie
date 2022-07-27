//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_GREENPLANT_H
#define PLANTVSZOMBIE_GREENPLANT_H
#include "ShooterPlant.h"

class GreenPlant : public ShooterPlant{
public:
    void shoot();

    GreenPlant(int x, int y);
};


#endif //PLANTVSZOMBIE_GREENPLANT_H
