//
// Created by Nayla on 28/09/2022.
//

#include <memory>
#include "Zombie.h"
Zombie::Zombie(float x,float y,ZombieType type) {
    this->type=type;
    this->initZombie();
    zombie.setPosition(x,y);
    this->update();


}
Zombie::~Zombie() {

};
void Zombie::initZombie() {
    switch(type){
        case ZombieType::BASIC:
            if(!texture.loadFromFile("../images/BasicZombie.png.png")){
                cout<<"No font is here";
            }
            this->zombie.setTexture(texture);
            this->health=10;
            this->damage=2;

            break;
        case ZombieType::TANK:
            if(!this->texture.loadFromFile("../images/TankZombie.png.png")){
                cout<<"No font is here";
            }
            this->zombie.setTexture(texture);
            this->zombie.setScale(0.5,0.5);
            this->health=15;
            this->damage=5;
            break;
    }

}

void Zombie::update() {
    this->zombie.move(-2.f,0);

}

void Zombie::renderZombie(RenderTarget *target) {
    target->draw(this->zombie);
}
//Accessors
FloatRect Zombie:: getBounds() const
{
    return this->zombie.getGlobalBounds();
}


