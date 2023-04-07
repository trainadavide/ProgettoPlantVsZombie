//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_BULLET_H
#define PLANTVSZOMBIE_BULLET_H
#define BULLETPOSX 0.036
#define BULLETSCALE 0.025
#define BULLETDIM 457


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
    const int getPosition();
    //to move
    FloatRect getBounds() const;

    const int getPower() const;

    bool isIce() const;

    Bullet(int power, bool ice, float x, int y, int screenSize);

    ~Bullet()=default;
};


#endif //PLANTVSZOMBIE_BULLET_H
