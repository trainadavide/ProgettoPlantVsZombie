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

