//
// Created by Nayla on 28/09/2022.
//

#include "Zombie.h"
Zombie::Zombie(float x,float y,ZombieType type) {
    this->type=type;

    float scale = (float)(PROPORTION_CONST*x)/ZOMBIES_IMAGES_DIM;
    initZombie(scale);
    zombie.setPosition(x,y);

    c=new Clock();
}
Zombie::~Zombie() = default;

void Zombie::initZombie(float scale) {
    switch(type){
        case ZombieType::BASIC:
            if(!texture.loadFromFile("./images/Sprites/BasicZombie.png")){
                cout<<"No font is here";
            }
            health=10;
            damage=2;
            zombie.setScale(scale,scale);
            break;
        case ZombieType::TANK:
            if(!texture.loadFromFile("./images/Sprites/TankZombie.png")){
                cout<<"No font is here";
            }
            zombie.setScale(scale,scale);
            health=15;
            damage=5;
            break;
        case ZombieType::SHOVEL:
            if(!texture.loadFromFile("./images/Sprites/ShovelZombie.png")){
                cout<<"No font is here";
            }
            zombie.setScale(scale,scale);
            health=15;
            damage=3;

            break;

    }
    zombie.setTexture(texture);
    speed=-5.5f;
    maxHealth = health;

    hpShape.setFillColor(sf::Color::Green);
    hpShape.setSize(sf::Vector2f(zombie.getGlobalBounds().width, zombie.getGlobalBounds().width/8));

}

void Zombie::update() {
    zombie.move(speed,0);
}

void Zombie::renderZombie(RenderTarget *target) {
    if(hitted) {
        if (c->getElapsedTime().asMilliseconds() >= 200)
            normalTexture();
    }
    target->draw(zombie);
    hpShape.setPosition(zombie.getPosition().x, zombie.getPosition().y + zombie.getGlobalBounds().height + hpShape.getGlobalBounds().height/2 );
    target->draw(hpShape);
}
//Accessors
FloatRect Zombie:: getBounds() const
{
    return zombie.getGlobalBounds();
}

void Zombie::setStatus(bool status) {
    this->status=status;
}

void Zombie::takeDamage(int power) {
    health-=power;
    hittedTexture();
    c->restart();
    hitted=true;
    hpShape.setSize(sf::Vector2f(zombie.getGlobalBounds().width*((float)health/(float)maxHealth), hpShape.getGlobalBounds().height));
}

bool Zombie::isDead() {
    if(health<=0)
        return true;
    else
        return false;
}

void Zombie::setSpeed(float speed) {
    Zombie::speed = speed;
}
const float Zombie::getSpeed() {
    return speed;
}

const int Zombie::getStrenght(){
    return damage;
}

void Zombie::hittedTexture() {
    switch(type) {
        case ZombieType::BASIC:
            if (!texture.loadFromFile("./images/Sprites/BasicZombieHitted.png")) {
                cout << "No font is here";
            }
            break;
        case ZombieType::TANK:
            if (!texture.loadFromFile("./images/Sprites/TankZombieHitted.png")) {
                cout << "No font is here";
            }

            break;
        case ZombieType::SHOVEL:
            if (!texture.loadFromFile("./images/Sprites/ShovelZombieHitted.png")) {
                cout << "No font is here";
            }
    }
}

void Zombie::normalTexture() {
    switch(type) {
        case ZombieType::BASIC:
            if (!texture.loadFromFile("./images/Sprites/BasicZombie.png")) {
                cout << "No font is here";
            }
            break;
        case ZombieType::TANK:
            if (!texture.loadFromFile("./images/Sprites/TankZombie.png")) {
                cout << "No font is here";
            }

            break;
        case ZombieType::SHOVEL:
            if (!texture.loadFromFile("./images/Sprites/ShovelZombie.png")) {
                cout << "No font is here";
            }
    }
}

bool Zombie::getHitted() {
    return hitted;
}

Sprite Zombie::getSprite(ZombieType type) {
    Zombie zombie(0,0,type);
    return zombie.zombie;
}

const ZombieType Zombie::getType(ZombieType type) {
    Zombie zombie(0,0,type);
    return zombie.type;
}

const int Zombie::getHealth() {
    return health;
}


