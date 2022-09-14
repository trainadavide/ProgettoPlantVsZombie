//
// Created by Nayla on 27/07/2022.
//

#include "BasicZombie.h"
#define BASIC_ZOMBIE_HEALTH 10
#define BASIC_ZOMBIE_DAMAGE 1

BasicZombie::BasicZombie(float x,int y):Zombie() {
    this->setHp(BASIC_ZOMBIE_HEALTH) ;
    this->setX(x);
    this->setY(y);
    this->setStrenght(BASIC_ZOMBIE_DAMAGE);
}