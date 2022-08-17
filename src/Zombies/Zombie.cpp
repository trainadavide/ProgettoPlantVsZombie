//
// Created by 0260863 on 26/07/2022.
//

#include "Zombie.h"
#include "stdio.h"
#include "../Plants/Plant.h"

Zombie::~Zombie(){
    delete this;
}


void Zombie::attack(Plant p) {
    p.takeDamage(this->strenght);
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
void Zombie::setStrenght(int strenght) {
    this->strenght=strenght;
}
int Zombie::getStrenght() const{
    return strenght;
}
void Zombie::setX(float x){
    this->x=x;
}
float Zombie::getX() const{
    return x;
}
void Zombie::setY(int y) {
    this->y=y;
}
int Zombie::getY() const {
    return y;
}

bool Zombie::getStatus() const {
    return iceStatus;
}

void Zombie::setStatus(bool status) {
    this->iceStatus = status;
}
