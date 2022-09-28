//
// Created by david on 14/09/2022.
//

#ifndef PLANTVSZOMBIE_BUTTON_H
#define PLANTVSZOMBIE_BUTTON_H
#include <SFML/Graphics.hpp>
#include "../Player.h"

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button {
public:
    Button(int position, sf::Texture &buttonImage);

    ~Button();

    void render(sf::RenderTarget* target);
    void update(sf::Vector2f mousePosition, Player& player);

    const bool isPressed() const;

private:

    sf::RectangleShape shape;
    sf::Texture buttonImage;
    int x;
    int y;
    short unsigned int plantID;

    short unsigned buttonState;
};


#endif //PLANTVSZOMBIE_BUTTON_H
