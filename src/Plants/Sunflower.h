//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_SUNFLOWER_H
#define PLANTVSZOMBIE_SUNFLOWER_H
#include "Plant.h"
#include "../Player.h"

class Sunflower : public Plant{
private:
    static const int type=0;
    sf::Sprite plant;
    sf::Texture t;
public:
    Sunflower(int x, int y);
    void draw(int posx, int posy, sf::RenderTarget* target);
    static void makeEnergy(Player &p);
};


#endif //PLANTVSZOMBIE_SUNFLOWER_H
