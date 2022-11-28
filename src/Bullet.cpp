//
// Created by david on 27/07/2022.
//

#include "Bullet.h"

Bullet::Bullet(int power, bool ice, float x, int y) : power(power), ice(ice), x(x), y(y) {
    this->power=power;
    this->ice=ice;
    this->x=x;
    this->y=y;

    this->bull.setPosition(x+100,y+30);
    this->bull.setScale(0.15,0.15);
    this->t.loadFromFile("../images/Sprites/Bullet.png");
    this->bull.setTexture(t);

    std::cout<<"Bullet";
}

void Bullet::miss() {
    this->Bullet::~Bullet();
}

void Bullet::hit(Zombie enemy) const{
    enemy.takeDamage(this->power);
    if(this->ice)
        enemy.setStatus(true);
}

void Bullet::draw(sf::RenderTarget *target) {
    target->draw(this->bull);
}

void Bullet::update() {
    this->bull.move({10,0});
}

