//
// Created by 0260863 on 27/07/2022.
//

#include "ShovelZombie.h"
#define SHOVEL_ZOMBIE_HEALTH 10
#define SHOVEL_ZOMBIE_DAMAGE 2

ShovelZombie::ShovelZombie(float x, int y):Zombie() {
    this->setHp(SHOVEL_ZOMBIE_HEALTH);
    this->setX(x);
    this->setY(y);
    this->setStrenght(SHOVEL_ZOMBIE_DAMAGE);
}