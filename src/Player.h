//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_PLAYER_H
#define PLANTVSZOMBIE_PLAYER_H
#define FONT_RESIZABLE 0.03
#define FONT_POSITION_X 0.37
#define FONT_POSITION_Y 0.0054
#define FONT_POSITION_Y_S 0.0356
#define INFO_DIM_X 0.2376
#define INFO_DIM_Y 0.0822
#define INFO_POS_X 0.365
#define INFO_POS_Y 0.0055

#include <SFML/Graphics.hpp>

class Player {
private:
    int energy; //Energy to place plants
    int selectedPlant=0; //selected plant's ID
    sf::RectangleShape playerInfo; //The info that shows up during the game
    sf::Font textFont;
    sf::Text energyDisplay;
    sf::Text selectedDisplay;
    void initFont();

public:
    Player(int energy, sf::Vector2<unsigned int> screenSize);
    void render(sf::RenderTarget* target); //Draw player info
    void update(); //Update player info
    void increaseEnergy();
    void select(int selected);
    void decreaseEnergy(int e);
    int getEnergy() const;
    int getSelectedPlant() const;
    sf::Text getenergyisplay() const;
};


#endif //PLANTVSZOMBIE_PLAYER_H
