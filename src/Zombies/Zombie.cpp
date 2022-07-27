//
// Created by 0260863 on 26/07/2022.
//

#include "Zombie.h"
#include "stdio.h"

Zombie::~Zombie(){
    delete this;
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
void Zombie::setHp(int hp) {
    this->hp=hp;
}
int Zombie::getHp() const {
    return hp;
}
void Zombie::setDamage(int damage) {
    this->damage=damage;
}
int Zombie::getDamage() const {} {
    return damage;
}
void Zombie::setX(float x){
    this->x=x;
}
int Zombie::getX() const{
    return x;
}
void Zombie::setY(int y) {
    this->y=y;
}
int Zombie::getY() const {
    return y;
}