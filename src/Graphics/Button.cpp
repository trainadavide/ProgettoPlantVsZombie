//
// Created by david on 14/09/2022.
//

#include "Button.h"
#define BUTTONSPOSY 10

Button::Button(int position, sf::Texture &buttonImage, int xSize) {

    this->plantID = position; //Plant ID for each button
    this->buttonImage = buttonImage; //Images on the buttons
    this->buttonState=BTN_IDLE; //button state is set on default (idle)

    //Makes the grid of buttons
    this->x=180*position;
    this->y= BUTTONSPOSY;
    this->shape.setPosition(sf::Vector2f((float)this->x,(float)this->y));

    this->shape.setSize(sf::Vector2f(xSize*BUTTON_SCALE,xSize*BUTTON_SCALE));
    this->shape.setTexture(&buttonImage);
}

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

//Update the button status
void Button::update(sf::Vector2f mousePosition, Player& player) {
    //Idle
    this->buttonState = BTN_IDLE; //status IDLE: mouse isn't over the button

    //Hover
    if(this->shape.getGlobalBounds().contains(mousePosition)){
        this->buttonState = BTN_HOVER; //status HOVER: mouse is over the button

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState = BTN_PRESSED; //status PRESSED: the player has selected the plant on this button
        }
    }

    switch (buttonState) {
        case BTN_IDLE:
            this->shape.setSize({150,150});
            break;

        case BTN_HOVER:
            this->shape.setSize({170,170}); //when mouse over button became bigger
            break;

        case BTN_PRESSED:
            player.select(plantID); //selected plant change
            break;

        default:
            break;
    }
    this->shape.setTexture(&buttonImage); //the image is applied on the button
}



