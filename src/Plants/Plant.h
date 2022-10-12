//
// Created by david on 26/07/2022.
//

#ifndef PLANTVSZOMBIE_PLANT_H
#define PLANTVSZOMBIE_PLANT_H
#include <SFML/Graphics.hpp>
#include <stdlib.h>


class Plant {

private:
    int x;
    int y;
    int hp;
    int cost;

public:
    int getHp() const;
    void setHp(int hp);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    int getCost() const;
    void setCost(int cost);

    void takeDamage(int damage);

    virtual void draw(int posx, int posy, sf::RenderTarget* target);

    ~Plant();
};


#endif //PLANTVSZOMBIE_PLANT_H
