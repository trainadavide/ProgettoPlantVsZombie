//
// Created by david on 27/07/2022.
//

#include "ShooterPlant.h"

ShooterPlant::ShooterPlant(int x, int y, ShooterType type, unsigned int screenXSize){
    this->x=x;
    this->y=y;
    this->type=type;
    this->setHp(SHOOTER_PLANT_HEALTH);
    float scale = ((float)SHOOTER_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;
    this->initType(scale);
}

void ShooterPlant::initType(float scale) {
    switch (type) {
        case ShooterType::GREEN:
            this->setCost(GREEN_PLANT_COST);
            this->t.loadFromFile("./images/Sprites/ShooterPlant.png");
            this->plant.setScale(scale,scale);
            break;
        case ShooterType::SNOW:
            this->setCost(SNOW_PLANT_COST);
            this->t.loadFromFile("./images/Sprites/SnowPlant.png");
            this->plant.setScale(scale,scale);
            break;
        case ShooterType::FIRE:
            this->setCost(FIRE_PLANT_COST);
            this->t.loadFromFile("./images/Sprites/FirePlant.png");
            this->plant.setScale(scale,scale);
            break;
    }
    plant.setTexture(t);
}

void ShooterPlant::shoot(std::vector<Bullet*> &bullets) {
    switch (type) {
        case ShooterType::GREEN:
            bullets.push_back(new Bullet(GREEN_PLANT_POWER, false, (float)this->plant.getPosition().x, this->plant.getPosition().y));
            break;
        case ShooterType::SNOW:
            bullets.push_back(new Bullet(SNOW_PLANT_POWER, true, (float)this->plant.getPosition().x, this->plant.getPosition().y));
            break;
        case ShooterType::FIRE:
            bullets.push_back(new Bullet(FIRE_PLANT_POWER, false, (float)this->plant.getPosition().x, this->plant.getPosition().y));
            break;
    }
}

void ShooterPlant::draw(int posx, int posy, sf::RenderTarget* target) {
    this->plant.setPosition(posx,posy);
    target->draw(this->plant);
}

char ShooterPlant::getType() {
    return 'p';
}

