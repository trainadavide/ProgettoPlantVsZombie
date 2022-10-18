//
// Created by Nayla on 28/09/2022.
//

#ifndef PLANTVSZOMBIE_ZOMBIE_H
#define PROPORTION_CONST 0.11
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
    //void isDead();
    //to draw
    void renderZombie(RenderTarget* target);
    //to move
    FloatRect getBounds() const;
private:
    int health;
    int damage;
    float speed;
    Texture texture;
    ZombieType type;
    Sprite zombie;
    void initZombie(float scale);


};


#endif //PLANTVSZOMBIE_ZOMBIE_H
