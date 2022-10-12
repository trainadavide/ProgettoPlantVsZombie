//
// Created by david on 27/07/2022.
//

#include "Nut.h"
Nut::Nut(int x, int y):Plant(){
    this->setX(x);
    this->setY(y);
    this->setHp(NUT_HEALTH);
    this->setCost(NUT_COST);
    this->plant.setScale(0.18,0.18);
    this->t.loadFromFile("../images/Sprites/Nut.png");
    this->plant.setTexture(t);
}

void Nut::draw(int posx, int posy, sf::RenderTarget* target) {
    this->plant.setPosition(posx,posy);
    target->draw(this->plant);
}