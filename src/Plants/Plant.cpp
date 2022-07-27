//
// Created by david on 26/07/2022.
//

#include "Plant.h"
#include "stdio.h"

Plant::~Plant() {
    delete this;
}

void Plant::takeDamage(int damage) {
    this->hp-=damage;

    if(this->hp <= 0) {
        printf("This plant died");
        this->Plant::~Plant();
    }
}

int Plant::getHp() const {
    return hp;
}

void Plant::setHp(int hp) {
    Plant::hp = hp;
}

int Plant::getX() const {
    return x;
}

void Plant::setX(int x) {
    Plant::x = x;
}

int Plant::getY() const {
    return y;
}

void Plant::setY(int y) {
    Plant::y = y;
}

int Plant::getCost() const {
    return cost;
}

void Plant::setCost(int cost) {
    Plant::cost = cost;
}

