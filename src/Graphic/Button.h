//
// Created by david on 08/09/2022.
//

#ifndef PLANTVSZOMBIE_BUTTON_H
#define PLANTVSZOMBIE_BUTTON_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Button {
public:
    Button(Vector2f size, int position){
        button.setSize(size);
        Texture back;
        back.loadFromFile("../immagini/ShooterPlant.jpg");

        button.setTexture(&back);

        float x = position*200;

        button.setPosition({x, 0});

    }

    void drawTo(RenderWindow &window){
        window.draw(button);
    }

    void setSize(Vector2f size){
        button.setSize(size);
    }

    bool isMouseOver(RenderWindow &window){
        float mouseX = Mouse::getPosition(window).x;
        float mouseY = Mouse::getPosition(window).y;

        float buttonX = button.getPosition().x;
        float buttonY = button.getPosition().y;

        float buttonPosWidth = buttonX + button.getLocalBounds().width;
        float buttonPosHeight = buttonY + button.getLocalBounds().height;

        if(mouseX > buttonX && mouseX < buttonPosWidth && mouseY > buttonY && mouseY < buttonPosHeight){
            return true;
        }
        return false;
    }

private:
    sf::RectangleShape button;
};


#endif //PLANTVSZOMBIE_BUTTON_H
