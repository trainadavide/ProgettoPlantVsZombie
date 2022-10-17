//
// Created by Nayla on 28/09/2022.
//

#ifndef PLANTVSZOMBIE_ZOMBIE_H
#define PLANTVSZOMBIE_ZOMBIE_H
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
    void initZombie();


};


#endif //PLANTVSZOMBIE_ZOMBIE_H
