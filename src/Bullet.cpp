//
// Created by david on 27/07/2022.
//

#include "Bullet.h"

Bullet::Bullet(int power, bool ice, float x, int y, int screenSize){
    this->power=power;
    this->ice=ice;

    int xpos = x + screenSize*BULLETPOSX;
    int ypos = y + (screenSize/4)*BULLETPOSX;

    this->bull.setPosition(xpos,ypos);
    this->bull.setScale(0.15,0.15);

    if(ice)
        this->t.loadFromFile("./images/Sprites/IceBullet.png");
    else if(power==2)
        this->t.loadFromFile("./images/Sprites/FireBullet.png");
    else
        this->t.loadFromFile("./images/Sprites/Bullet.png");

    this->bull.setTexture(t);
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

int Bullet::getPosition(){
    return this->bull.getPosition().x;
}
