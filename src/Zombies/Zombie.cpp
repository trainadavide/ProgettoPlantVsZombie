//
// Created by Nayla on 26/07/2022.
//

#include "Zombie.h"
#include "../Game.h"

void Zombie::initShape() {
    Texture z;
    z.loadFromFile("../images/Zombie.png");
    this->zombie.setTexture(z);
    this-> zombie.setTextureRect(IntRect(50,50,50,50));
}

void Zombie::initVariables() {
    this->type=0;
    this->hp=0;
    this->hpMAx=0;
    this->damage=0;
    this->points=0;
}
//functions

void Zombie::update() {
    this->zombie.move(-5.f,0);
}
void Zombie::render(sf::RenderTarget *target) {
    target->draw(this->zombie);
}

Zombie::Zombie(float posX,float posY) {
    this->initShape();
    this->initVariables();
    this->zombie.setPosition(posX,posY);

}

Zombie::~Zombie(){

}
//Accessors
FloatRect Zombie:: getBounds() const
{
    return this->zombie.getGlobalBounds();
};
