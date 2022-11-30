//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_BULLET_H
#define PLANTVSZOMBIE_BULLET_H
#define BULLETPOSX 0.036


#include "Zombies/Zombie.h"

class Bullet {
private:
    int power;
    bool ice;
    sf::Sprite bull;
    sf::Texture t;

public:
    void hit(Zombie enemy) const;

    void draw(sf::RenderTarget *target);
    void update();
    int getPosition();

    Bullet(int power, bool ice, float x, int y, int screenSize);

    ~Bullet()=default;
};


#endif //PLANTVSZOMBIE_BULLET_H
