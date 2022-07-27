//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_FIREPLANT_H
#define PLANTVSZOMBIE_FIREPLANT_H
#include "ShooterPlant.h"

class FirePlant : public ShooterPlant{
public:
    void shoot();

    FirePlant(int x, int y);
};



#endif //PLANTVSZOMBIE_FIRELANT_H
