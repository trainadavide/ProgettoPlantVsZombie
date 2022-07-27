//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_SNOWPLANT_H
#define PLANTVSZOMBIE_SNOWPLANT_H
#include "ShooterPlant.h"

class SnowPlant : public ShooterPlant{
public:
    void shoot();

    SnowPlant(int x, int y);
};



#endif //PLANTVSZOMBIE_SNOWPLANT_H
