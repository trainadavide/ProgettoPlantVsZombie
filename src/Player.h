//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_PLAYER_H
#define PLANTVSZOMBIE_PLAYER_H

#include "Map.h"
#include <SFML/Graphics.hpp>

class Player {
private:
    int energy;
    int time;
    int selectedPlant;
    sf::RectangleShape playerInfo;
    sf::Font textFont;
    sf::Text energyDisplay;
    void initFont();

public:
    Player(int energy);
    void render(sf::RenderTarget* target);
    void update(sf::RenderTarget* target);
    void increaseEnergy();
    void select(int selected);
    void place(Map m, int x, int y);
};


#endif //PLANTVSZOMBIE_PLAYER_H
