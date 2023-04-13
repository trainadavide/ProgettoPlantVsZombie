//
// Created by david on 27/07/2022.
//

#include "Bullet.h"

Bullet::Bullet(int power, bool ice, float x, int y, int screenSize){
    this->power=power;
    this->ice=ice;

    int xpos = x + screenSize*BULLETPOSX;
    int ypos = y + (screenSize/4)*BULLETPOSX;

    bull.setPosition(xpos,ypos);
    bull.setScale((screenSize*BULLETSCALE)/BULLETDIM,(screenSize*BULLETSCALE)/BULLETDIM);

    if(ice)
        t.loadFromFile("./images/Sprites/IceBullet.png");
    else if(power==2)
        t.loadFromFile("./images/Sprites/FireBullet.png");
    else
        t.loadFromFile("./images/Sprites/Bullet.png");

    bull.setTexture(t);
}

void Bullet::hit(Zombie enemy) const{
    enemy.takeDamage(power);
    if(ice)
        enemy.setStatus(true);
}

void Bullet::draw(sf::RenderTarget *target) {
    target->draw(bull);
}

void Bullet::update() {
    bull.move({10,0});
}

int Bullet::getPosition() const{
    return bull.getPosition().x;
}

FloatRect Bullet::getBounds() const {
    return bull.getGlobalBounds();
}

int Bullet::getPower() const {
    return power;
}

bool Bullet::isIce() const {
    return ice;
}
