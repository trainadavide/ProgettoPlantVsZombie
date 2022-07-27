//
// Created by david on 27/07/2022.
//

#include "Bullet.h"

void Bullet::miss() {
    this->Bullet::~Bullet();
}

Bullet::~Bullet() {
}

Bullet::Bullet(int power, bool ice, float x, int y) : power(power), ice(ice), x(x), y(y) {}
