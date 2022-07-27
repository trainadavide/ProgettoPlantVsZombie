//
// Created by 0260863 on 27/07/2022.
//

#include "BasicZombie.h"

BasicZombie::BasicZombie(float x,int y):Zombie() {
    this->hp=10;
    this->x=x;
    this->y=y;
    this->damage=1;
}