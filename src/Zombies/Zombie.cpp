//
// Created by Nayla on 28/09/2022.
//

#include <memory>
#include "Zombie.h"
Zombie::Zombie(float x,float y,ZombieType type) {
    this->type=type;

    float scale = (PROPORTION_CONST*x)/ZOMBIES_IMAGES_DIM;
    this->initZombie(scale);
    zombie.setPosition(x,y);
    this->update();


}
Zombie::~Zombie() {

};
void Zombie::initZombie(float scale) {
    switch(type){
        case ZombieType::BASIC:
            if(!texture.loadFromFile("../images/Sprites/BasicZombie.png")){
                cout<<"No font is here";
            }
            this->health=10;
            this->damage=2;
            this->zombie.setScale(scale,scale);
            break;
        case ZombieType::TANK:
            if(!this->texture.loadFromFile("../images/Sprites/TankZombie.png")){
                cout<<"No font is here";
            }
            this->zombie.setScale(scale,scale);
            this->health=15;
            this->damage=5;
            break;
        case ZombieType::SHOVEL:
            if(!this->texture.loadFromFile("../images/Sprites/ShovelZombie.png")){
                cout<<"No font is here";
            }
            this->zombie.setScale(scale,scale);
            this->health=15;
            this->damage=3;

            break;

    }
    this->zombie.setTexture(texture);
    this->speed=-5.5f;

}

void Zombie::update() {
    this->zombie.move(speed,0);

}

void Zombie::renderZombie(RenderTarget *target) {
    target->draw(this->zombie);
}
//Accessors
FloatRect Zombie:: getBounds() const
{
    return this->zombie.getGlobalBounds();
}


