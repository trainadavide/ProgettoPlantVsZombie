//
// Created by 0260863 on 26/07/2022.
//

#include "Zombie.h"
#include "stdio.h"

Zombie::~Zombie(){
    delete this;
}

Zombie::Zombie(int hp,float x,int y,int damage) {
    this->hp=hp;
    this->x=x;
    this->y=y;
    this->damage=damage;
}

void Zombie::attack(Plant p) {
    p.takeDamage(this->damage);
}

void Zombie::takeDamage(int damage) {
    this->hp-=damage;
    if(this->hp<=0){
        this->Zombie::~Zombie();
    }
}
