//
// Created by Nayla on 28/09/2022.
//

#ifndef PLANTVSZOMBIE_ZOMBIE_H
#define PROPORTION_CONST 0.095
#define ZOMBIES_IMAGES_DIM 360
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace sf;
using namespace std;

enum class ZombieType{
    BASIC,TANK,SHOVEL
};
class Zombie {
public:
    //constructor & distructor
    Zombie(float x,float y, ZombieType type);
    ~Zombie();
    //functions
    void update();
    //set iced status
    void setStatus(bool status);
    //to draw
    void renderZombie(RenderTarget* target);
    //to move
    FloatRect getBounds() const;
    //zombie get hit
    void takeDamage(int power);
    //getter and setter
    Sprite getSprite(ZombieType type);
    ZombieType getType(ZombieType type);
    void setSpeed(float speed);
    float getSpeed();
    bool isDead();
    int getStrenght();
    int getHealth();
    bool getHitted();

private:
    Sprite zombie;
    Texture texture;
    ZombieType type;
    int health;
    int damage;
    int maxHealth;
    float speed;
    bool status;
    RectangleShape hpShape;
    void initZombie(float scale);
    void hittedTexture();
    void normalTexture();
    Clock* c= nullptr;
    bool hitted=false;

};


#endif //PLANTVSZOMBIE_ZOMBIE_H
