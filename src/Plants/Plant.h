//
// Created by david on 26/07/2022.
//

#ifndef PLANTVSZOMBIE_PLANT_H
#define PLANTVSZOMBIE_PLANT_H
#include <SFML/Graphics.hpp>
#define SUNFLOWER_HEALTH 10
#define NUT_HEALTH 30
#define BASIC_COST 2
#define PLANT_PROPORTION_CONST 0.08
#define SHOOTER_PROPORTION_CONST 0.073
#define PLANTS_IMAGES_DIM 1700
#include <cstdlib>
#include "../Player.h"
#include "../Bullet.h"

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
    void setHp(int hp);

    int getX() const;

    int getY() const;

    int getHp() const;

    void setCost(int cost);

    virtual char getType();

    void takeDamage(int damage);

    virtual void shoot(std::vector<Bullet*> &bullets, int screensize){};

    virtual void draw(int posx, int posy, sf::RenderTarget* target);

    virtual FloatRect getBounds() const;

    static void makeEnergy(Player &p);

    Plant(int x, int y, PlantType type,unsigned int screenXSize);
    Plant();
    ~Plant()=default;


};


#endif //PLANTVSZOMBIE_PLANT_H
