//
// Created by david on 27/07/2022.
//

#include "ShooterPlant.h"

ShooterPlant::ShooterPlant(int x, int y, ShooterType type){
    this->x=x;
    this->y=y;
    this->type=type;
    this->setHp(SHOOTER_PLANT_HEALTH);
    this->initType();
}

void ShooterPlant::initType() {
    switch (type) {
        case ShooterType::GREEN:
            this->setCost(GREEN_PLANT_COST);
            this->t.loadFromFile("../images/Sprites/ShooterPlant.png");
            this->plant.setScale(0.2,0.2);
            break;
        case ShooterType::SNOW:
            this->setCost(SNOW_PLANT_COST);
            this->t.loadFromFile("../images/Sprites/SnowPlant.png");
            this->plant.setScale(0.22,0.22);
            break;
        case ShooterType::FIRE:
            this->setCost(FIRE_PLANT_COST);
            this->t.loadFromFile("../images/Sprites/FirePlant.png");
            this->plant.setScale(0.13,0.13);
            break;
    }
    plant.setTexture(t);
}

void ShooterPlant::shoot() {
    std::unique_ptr<Bullet> b;
    switch (type) {
        case ShooterType::GREEN:
            b = std::unique_ptr<Bullet> (new Bullet(GREEN_PLANT_POWER, false, (float)this->getX(), this->getY()));
            break;
        case ShooterType::SNOW:
            b = std::unique_ptr<Bullet> (new Bullet(SNOW_PLANT_POWER, true, (float)this->getX(), this->getY()));
            break;
        case ShooterType::FIRE:
            b = std::unique_ptr<Bullet> (new Bullet(FIRE_PLANT_POWER, false, (float)this->getX(), this->getY()));
            break;
    }
}

void ShooterPlant::draw(int posx, int posy, sf::RenderTarget* target) {
    this->plant.setPosition(posx,posy);
    target->draw(this->plant);
}

