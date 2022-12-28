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
    cost=BASIC_COST;//Sunflower and Nut has the same cost

    float scale = ((float)PLANT_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;/*The dimension (in pixels) of the plants is scaled
    considering the screen resolution*/

    switch (type) {
        case PlantType::SUNFLOWER:
            hp=SUNFLOWER_HEALTH;
            plant.setScale(scale,scale); //dimension is set with the scale calculated before
            t.loadFromFile("./images/Sprites/sunflower.png"); //sunflower image
            plant.setTexture(t);
            break;
        case PlantType::NUT:
            hp=NUT_HEALTH;
            plant.setScale(scale,scale); //dimension is set with the scale calculated before
            t.loadFromFile("./images/Sprites/Nut.png"); //nut image
            plant.setTexture(t);
            break;
    }
}

void Plant::takeDamage(int damage) {
    hp-=damage;
}

//used to distinguish a type of plant from another on the map
char Plant::getType() {
    switch (type) {
        case PlantType::SUNFLOWER:
            return 's';
        case PlantType::NUT:
            return 'n';
    }
}

//used in the class ShooterPlant to set plant hp
void Plant::setHp(int healthpoint) {
    hp = healthpoint;
}
int Plant::getX() const {
    return x;
}
int Plant::getY() const {
    return y;
}
int Plant::getHp() const {
    return hp;
}
//used in the class ShooterPlant to set plant cost
void Plant::setCost(int c) {
    Plant::cost = c;
}

//Plant is drawn on the target, target refers to the window
void Plant::draw(int posx, int posy, sf::RenderTarget* target) {
    plant.setPosition((float)posx,(float)posy);
    target->draw(plant);
}

//if the plant is a sunflower it can produce energy
void Plant::makeEnergy(Player &p) {
        p.increaseEnergy();
}

FloatRect Plant:: getBounds() const
{
    return plant.getGlobalBounds();
}

Plant::Plant() = default; // NOLINT(cppcoreguidelines-pro-type-member-init)


