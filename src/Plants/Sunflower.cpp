//
// Created by david on 27/07/2022.
//

#include "Sunflower.h"
#define SUNFLOWER_HEALTH 10
#define SUNFLOWER_COST 2

Sunflower::Sunflower(int x, int y):Plant(){
    this->setX(x);
    this->setY(y);
    this->setHp(SUNFLOWER_HEALTH);
    this->setCost(SUNFLOWER_COST);
    this->plant.setScale(0.15,0.15);
    this->t.loadFromFile("../images/Sprites/sunflower.png");
    this->plant.setTexture(t);
}

void Sunflower::makeEnergy(Player &p) {
    p.increaseEnergy();
}

void Sunflower::draw(int posx, int posy, sf::RenderTarget* target) {
    this->plant.setPosition(posx,posy);
    target->draw(this->plant);
}