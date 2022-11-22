//
// Created by david on 26/07/2022.
//

#include "Plant.h"
#include "cstdio"

Plant::Plant(int x, int y, PlantType type, unsigned int screenXSize) {
    //Plant position
    this->x=x;
    this->y=y;

    this->type=type;
    this->cost=BASIC_COST;//Sunflower and Nut has the same cost

    float scale = ((float)PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;/*The dimension (in pixels) of the plants is scaled
    considering the screen resolution*/

    switch (type) {
        case PlantType::SUNFLOWER:
            this->hp=SUNFLOWER_HEALTH;
            this->plant.setScale(scale,scale); //dimension is set with the scale calculated before
            this->t.loadFromFile("../images/Sprites/sunflower.png"); //sunflower image
            this->plant.setTexture(t);
            break;
        case PlantType::NUT:
            this->hp=NUT_HEALTH;
            this->plant.setScale(scale,scale); //dimension is set with the scale calculated before
            this->t.loadFromFile("../images/Sprites/Nut.png"); //nut image
            this->plant.setTexture(t);
            break;
    }
}

void Plant::takeDamage(int damage) {
    this->hp-=damage;

    //if the hp are less or equal to zero -> call the destructor
    if(this->hp <= 0) {
        printf("This plant died");
        this->Plant::~Plant();
    }
}

//used to distinguish a type of plant from another on the map
char Plant::getType() {
    switch (this->type) {
        case PlantType::SUNFLOWER:
            return 's';
        case PlantType::NUT:
            return 'n';
        default:
            return 'p';
    }
}

//used in the class ShooterPlant to set plant hp
void Plant::setHp(int healthpoint) {
    this->hp = healthpoint;
}
int Plant::getX() const {
    return x;
}
int Plant::getY() const {
    return y;
}
//used in the class ShooterPlant to set plant cost
void Plant::setCost(int c) {
    Plant::cost = c;
}

//Plant is drawn on the target, target refers to the window
void Plant::draw(int posx, int posy, sf::RenderTarget* target) {
    this->plant.setPosition((float)posx,(float)posy);
    target->draw(this->plant);
}

//if the plant is a sunflower it can produce energy
void Plant::makeEnergy(Player &p) {
        p.increaseEnergy();
}


Plant::Plant() = default; // NOLINT(cppcoreguidelines-pro-type-member-init)


