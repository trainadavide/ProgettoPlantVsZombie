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
    //zombie get hitted
    void takeDamage(int power);

    void setSpeed(float speed);
    bool isDead();
    int getStrenght();
private:
    int health;
    int damage;
    float speed;
    Texture texture;
    ZombieType type;
    Sprite zombie;
    bool status;
    void initZombie(float scale);
    void hittedTexture();
    void normalTexture();
    Clock* c= nullptr;

};


#endif //PLANTVSZOMBIE_ZOMBIE_H
