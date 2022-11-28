//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_BUTTON_H
#define PLANTVSZOMBIE_BUTTON_H
#include <SFML/Graphics.hpp>
#include "../Player.h"
#define BUTTON_SCALE 0.055
#define BUTTON_BIG_SCALE 0.062
#define BUTTON_DIS 0.066

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button {
public:
    Button(int position, sf::Texture &buttonImage, int xSize);

    ~Button() = default;

    void render(sf::RenderTarget* target); //button render
    void update(sf::Vector2f mousePosition, Player& player, int xSize); //Update the button status

private:

    sf::RectangleShape shape; //the actual shape of the button
    sf::Texture buttonImage;
    int x;
    int y;
    short unsigned int plantID; //plantID associated to each button

    short unsigned buttonState; //status
};


#endif //PLANTVSZOMBIE_BUTTON_H
