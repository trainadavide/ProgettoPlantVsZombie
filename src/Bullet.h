//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_BULLET_H
#define PLANTVSZOMBIE_BULLET_H

#include "Zombies/Zombie.h"

class Bullet {
private:
    int power;
    bool ice;
    float x;
    int y;

public:
    void miss();
    void hit(Zombie enemy) const;

    Bullet(int power, bool ice, float x, int y);

    ~Bullet()=default;
};


#endif //PLANTVSZOMBIE_BULLET_H
