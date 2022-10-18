//
// Created by david on 26/07/2022.
//

#ifndef PLANTVSZOMBIE_PLANT_H
#define PLANTVSZOMBIE_PLANT_H
#include <SFML/Graphics.hpp>
#define SUNFLOWER_HEALTH 10
#define SUNFLOWER_COST 2
#define PROPORTION_CONST 0.08
#define SHOOTER_PROPORTION_CONST 0.073
#define PLANTS_IMAGES_DIM 1700
#include <cstdlib>
#include "../Player.h"

enum class PlantType{
    SUNFLOWER, NUT
};

class Plant {

private:
    int x;
    int y;
    int hp;
    int cost;
    PlantType type;
    sf::Sprite plant;
    sf::Texture t;

public:
    int getHp() const;
    void setHp(int hp);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    int getCost() const;
    void setCost(int cost);

    char getType() const;

    void takeDamage(int damage);

    virtual void draw(int posx, int posy, sf::RenderTarget* target);

    static void makeEnergy(Player &p);

    Plant(int x, int y, PlantType type,float screenXSize);
    Plant();
    ~Plant()=default;


};


#endif //PLANTVSZOMBIE_PLANT_H
