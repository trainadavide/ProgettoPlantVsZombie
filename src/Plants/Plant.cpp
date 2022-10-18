//
// Created by david on 26/07/2022.
//

#include "Plant.h"
#include "cstdio"

Plant::Plant(int x, int y, PlantType type, float screenXSize) {
    this->x=x;
    this->y=y;
    this->hp=SUNFLOWER_HEALTH;
    this->cost=SUNFLOWER_COST;
    this->type=type;
    float scale = (PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;
    switch (type) {
        case PlantType::SUNFLOWER:
            this->plant.setScale(scale,scale);
            this->t.loadFromFile("../images/Sprites/sunflower.png");
            this->plant.setTexture(t);
            break;
        case PlantType::NUT:
            this->plant.setScale(scale,scale);
            this->t.loadFromFile("../images/Sprites/Nut.png");
            this->plant.setTexture(t);
            break;
    }
}

void Plant::takeDamage(int damage) {
    this->hp-=damage;

    if(this->hp <= 0) {
        printf("This plant died");
        this->Plant::~Plant();
    }
}

char Plant::getType() const {
    switch (this->type) {
        case PlantType::SUNFLOWER:
            return 's';
        case PlantType::NUT:
            return 'n';
        default:
            return 'a';
    }
}
int Plant::getHp() const {
    return hp;
}
void Plant::setHp(int hp) {
    this->hp = hp;
}
int Plant::getX() const {
    return x;
}
void Plant::setX(int x) {
    Plant::x = x;
}
int Plant::getY() const {
    return y;
}
void Plant::setY(int y) {
    Plant::y = y;
}
int Plant::getCost() const {
    return cost;
}
void Plant::setCost(int cost) {
    Plant::cost = cost;
}


void Plant::draw(int posx, int posy, sf::RenderTarget* target) {
    this->plant.setPosition((float)posx,(float)posy);
    target->draw(this->plant);
}

void Plant::makeEnergy(Player &p) {
        p.increaseEnergy();
}

Plant::Plant() = default; // NOLINT(cppcoreguidelines-pro-type-member-init)


