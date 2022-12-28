//
// Created by david on 27/07/2022.
//

#include "ShooterPlant.h"

ShooterPlant::ShooterPlant(int x, int y, ShooterType type, unsigned int screenXSize){
    this->x=x;
    this->y=y;
    this->type=type;
    setHp(SHOOTER_PLANT_HEALTH);
    float scale = ((float)SHOOTER_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;
    initType(scale);
}

void ShooterPlant::initType(float scale) {
    switch (type) {
        case ShooterType::GREEN:
            setCost(GREEN_PLANT_COST);
            t.loadFromFile("./images/Sprites/ShooterPlant.png");
            plant.setScale(scale,scale);
            break;
        case ShooterType::SNOW:
            setCost(SNOW_PLANT_COST);
            t.loadFromFile("./images/Sprites/SnowPlant.png");
            plant.setScale(scale,scale);
            break;
        case ShooterType::FIRE:
            setCost(FIRE_PLANT_COST);
            t.loadFromFile("./images/Sprites/FirePlant.png");
            plant.setScale(scale,scale);
            break;
    }
    plant.setTexture(t);
}

void ShooterPlant::shoot(std::vector<Bullet*> &bullets, int screensize) {
    switch (type) {
        case ShooterType::GREEN:
            bullets.push_back(new Bullet(GREEN_PLANT_POWER, false, (float)plant.getPosition().x, plant.getPosition().y,screensize));
            break;
        case ShooterType::SNOW:
            bullets.push_back(new Bullet(SNOW_PLANT_POWER, true, (float)plant.getPosition().x, plant.getPosition().y,screensize));
            break;
        case ShooterType::FIRE:
            bullets.push_back(new Bullet(FIRE_PLANT_POWER, false, (float)plant.getPosition().x, plant.getPosition().y,screensize));
            break;
    }
}

void ShooterPlant::draw(int posx, int posy, sf::RenderTarget* target) {
    plant.setPosition(posx,posy);
    target->draw(plant);
}

char ShooterPlant::getType() {
    return 'p';
}

FloatRect ShooterPlant::getBounds() const {
    return plant.getGlobalBounds();
}

