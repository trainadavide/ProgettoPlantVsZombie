//
// Created by david on 26/07/2022.
//

#include "Plant.h"
#include "cstdio"

Plant::Plant(int x, int y, PlantType type, unsigned int screenXSize) {
    //Plant position
    this->x=x;
    this->y=y;
    c = new Clock();

    this->type=type;
    cost=BASIC_COST;//Sunflower and Nut has the same cost

    float scale = ((float)PLANT_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;/*The dimension (in pixels) of the plants is scaled
    considering the screen resolution*/

    switch (type) {
        case PlantType::SUNFLOWER:
            hp=SUNFLOWER_HEALTH;
            plant.setScale(scale,scale); //dimension is set with the scale calculated before
            t.loadFromFile("./images/Sprites/sunflower.png"); //sunflower image
            break;
        case PlantType::NUT:
            hp=NUT_HEALTH;
            plant.setScale(scale,scale); //dimension is set with the scale calculated before
            t.loadFromFile("./images/Sprites/Nut.png"); //nut image
            break;
        case PlantType::GREEN:
            scale = ((float)SHOOTER_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;
            hp=SHOOTER_PLANT_HEALTH;
            cost=GREEN_PLANT_COST;
            t.loadFromFile("./images/Sprites/ShooterPlant.png");
            plant.setScale(scale,scale);
            break;
        case PlantType::SNOW:
            scale = ((float)SHOOTER_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;
            hp=SHOOTER_PLANT_HEALTH;
            cost=SNOW_PLANT_COST;
            t.loadFromFile("./images/Sprites/SnowPlant.png");
            plant.setScale(scale,scale);
            break;
        case PlantType::FIRE:
            scale = ((float)SHOOTER_PROPORTION_CONST*screenXSize)/PLANTS_IMAGES_DIM;
            hp=SHOOTER_PLANT_HEALTH;
            cost=FIRE_PLANT_COST;
            t.loadFromFile("./images/Sprites/FirePlant.png");
            plant.setScale(scale,scale);
            break;
    }
    plant.setTexture(t);
    maxHealth=hp;
    hpShape.setFillColor(sf::Color::Green);
    hpShape.setSize(sf::Vector2f(plant.getGlobalBounds().width, plant.getGlobalBounds().width/8));
}

void Plant::takeDamage(int damage) {
    hp-=damage;
    hittedTexture();
    c->restart();
    hitted=true;
    hpShape.setSize(sf::Vector2f(plant.getGlobalBounds().width*((float)hp/(float)maxHealth), hpShape.getGlobalBounds().height));

}

//used to distinguish a type of plant from another on the map
char Plant::getType() {
    switch (type) {
        case PlantType::SUNFLOWER:
            return 's';
        case PlantType::NUT:
            return 'n';
        default:
            return 'p';
    }
}

int Plant::getHp() const {
    return hp;
}

//Plant is drawn on the target, target refers to the window
void Plant::draw(int posx, int posy, sf::RenderTarget* target) {
    plant.setPosition((float)posx,(float)posy);
    if(hitted){
        if(c->getElapsedTime().asMilliseconds()>=200) {
            normalTexture();
            hitted=false;
        }
    }

    hpShape.setPosition(plant.getPosition().x, plant.getPosition().y + plant.getGlobalBounds().height + hpShape.getGlobalBounds().height/2 );
    target->draw(plant);
    target->draw(hpShape);
}

//if the plant is a sunflower it can produce energy
void Plant::makeEnergy(Player &p) {
        p.increaseEnergy();
}

FloatRect Plant:: getBounds() const
{
    return plant.getGlobalBounds();
}

void Plant::hittedTexture() {
    switch (type) {
        case PlantType::SUNFLOWER:
            t.loadFromFile("./images/Sprites/sunflowerHitted.png"); //sunflower image
            break;
        case PlantType::NUT:
            t.loadFromFile("./images/Sprites/NutHitted.png"); //nut image
            break;
        case PlantType::GREEN:
            t.loadFromFile("./images/Sprites/ShooterPlantHitted.png");
            break;
        case PlantType::SNOW:
            t.loadFromFile("./images/Sprites/SnowPlantHitted.png");
            break;
        case PlantType::FIRE:
            t.loadFromFile("./images/Sprites/FirePlantHitted.png");
            break;
    }
    plant.setTexture(t);
}

void Plant::normalTexture(){
    switch (type) {
        case PlantType::SUNFLOWER:
            t.loadFromFile("./images/Sprites/sunflower.png"); //sunflower image
            break;
        case PlantType::NUT:
            t.loadFromFile("./images/Sprites/Nut.png"); //nut image
            break;
        case PlantType::GREEN:
            t.loadFromFile("./images/Sprites/ShooterPlant.png");
            break;
        case PlantType::SNOW:
            t.loadFromFile("./images/Sprites/SnowPlant.png");
            break;
        case PlantType::FIRE:
            t.loadFromFile("./images/Sprites/FirePlant.png");
            break;
    }
    plant.setTexture(t);
}

Clock* Plant::getClock() {
    return c;
}

void Plant::shoot(vector<Bullet *> &bullets, int screensize) {
    switch (type) {
        case PlantType::GREEN:
            bullets.push_back(new Bullet(GREEN_PLANT_POWER, false, (float)plant.getPosition().x, plant.getPosition().y,screensize));
            break;
        case PlantType::SNOW:
            bullets.push_back(new Bullet(SNOW_PLANT_POWER, true, (float)plant.getPosition().x, plant.getPosition().y,screensize));
            break;
        case PlantType::FIRE:
            bullets.push_back(new Bullet(FIRE_PLANT_POWER, false, (float)plant.getPosition().x, plant.getPosition().y,screensize));
            break;
    }
}

Sprite Plant::getSprite(PlantType Type) {
    Plant plant(0,0,Type,30);
    return plant.plant;
}

bool Plant::getHitted() {
    return hitted;
}


Plant::Plant() = default; // NOLINT(cppcoreguidelines-pro-type-member-init)


