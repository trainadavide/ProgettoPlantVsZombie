//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_PLAYER_H
#define PLANTVSZOMBIE_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    int energy;
    int selectedPlant=0;
    sf::RectangleShape playerInfo;
    sf::Font textFont;
    sf::Text energyDisplay;
    sf::Text selectedDisplay;
    void initFont();

public:
    explicit Player(int energy);
    void render(sf::RenderTarget* target);
    void update();
    void increaseEnergy();
    void select(int selected);
    void decreaseEnergy(int e);
    int getEnergy() const;
    int getSelectedPlant() const;
};


#endif //PLANTVSZOMBIE_PLAYER_H
