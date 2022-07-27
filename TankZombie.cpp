//
// Created by 0260863 on 27/07/2022.
//

#include "TankZombie.h"


TankZombie::TankZombie(float x, int y):Zombie() {
    this->hp=20;
    this->x=x;
    this->y=y;
    this->damage=1;
}