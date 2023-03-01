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
#define SHOOTER_PLANT_HEALTH 10
#define GREEN_PLANT_POWER 1
#define GREEN_PLANT_COST 4
#define FIRE_PLANT_POWER 2
#define FIRE_PLANT_COST 7
#define SNOW_PLANT_POWER 1
#define SNOW_PLANT_COST 7
#include <cstdlib>
#include "../Player.h"
#include "../Bullet.h"

enum class PlantType{
    SUNFLOWER, NUT, GREEN, SNOW, FIRE
};

class Plant {

private:
    int x;
    int y;
    int hp;
    int cost;
    PlantType type;
    Sprite plant;
    sf::Texture t;
    void hittedTexture();
    void normalTexture();
    Clock* c = nullptr;
    bool hitted=false;

public:
    Clock* getClock();

    int getHp() const;

    char getType();

    bool getHitted();
    Sprite getSprite(PlantType Type);

    void takeDamage(int damage);

    void shoot(std::vector<Bullet*> &bullets, int screensize);

    void draw(int posx, int posy, sf::RenderTarget* target);

    FloatRect getBounds() const;

    static void makeEnergy(Player &p);

    Plant(int x, int y, PlantType type,unsigned int screenXSize);
    Plant();
    ~Plant()=default;


};


#endif //PLANTVSZOMBIE_PLANT_H
