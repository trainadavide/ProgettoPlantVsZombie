//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_NUT_H
#define PLANTVSZOMBIE_NUT_H

#include "Plant.h"
#include <SFML/Graphics.hpp>

#define NUT_HEALTH 20
#define NUT_COST 2

class Nut : public Plant{
private:
    static const int type=1;
    sf::Sprite plant;
    sf::Texture t;
public:
    Nut(int x, int y);
    void draw(int posx, int posy, sf::RenderTarget* target);
};


#endif //PLANTVSZOMBIE_NUT_H
