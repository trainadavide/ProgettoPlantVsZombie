//
// Created by Nayla on 27/07/2022.
//

#include "TankZombie.h"
#define TANK_ZOMBIE_HEALTH 20
#define TANK_ZOMBIE_DAMAGE 1

TankZombie::TankZombie(float x, int y):Zombie() {
    this->setHp(TANK_ZOMBIE_HEALTH);
    this->setX(x);
    this->setY(y);
    this->setStrenght(TANK_ZOMBIE_DAMAGE);
}