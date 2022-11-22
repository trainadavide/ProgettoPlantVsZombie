//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_SHOOTERPLANT_H
#define PLANTVSZOMBIE_SHOOTERPLANT_H

#define SHOOTER_PLANT_HEALTH 10
#define GREEN_PLANT_POWER 1
#define GREEN_PLANT_COST 4
#define FIRE_PLANT_POWER 2
#define FIRE_PLANT_COST 7
#define SNOW_PLANT_POWER 1
#define SNOW_PLANT_COST 7

#include "Plant.h"
#include "../Bullet.h"
#include <SFML/Graphics.hpp>
#include <memory>
enum class ShooterType{
    GREEN, SNOW, FIRE
};

class ShooterPlant : public Plant{
private:
    ShooterType type;
    sf::Sprite plant;
    sf::Texture t;
    int x, y;
    void initType(float scale);
public:
    ShooterPlant(int x, int y, ShooterType type, unsigned int screenXSize);
    void shoot();
    void draw(int posx, int posy, sf::RenderTarget* target) override;
};


#endif //PLANTVSZOMBIE_SHOOTERPLANT_H
