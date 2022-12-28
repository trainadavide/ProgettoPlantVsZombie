//
// Created by david on 14/09/2022.
//

#include "Button.h"
#define BUTTONSPOSY 10

Button::Button(int position, sf::Texture &buttonImage, int xSize) {

    plantID = position; //Plant ID for each button
    this->buttonImage = buttonImage; //Images on the buttons
    buttonState=BTN_IDLE; //button state is set on default (idle)

    //Makes the grid of buttons
    x=BUTTON_DIS*xSize*position;
    y= BUTTONSPOSY;
    shape.setPosition(sf::Vector2f((float)x,(float)y));

    shape.setSize(sf::Vector2f(xSize*BUTTON_SCALE,xSize*BUTTON_SCALE));
    shape.setTexture(&buttonImage);
}

void Button::render(sf::RenderTarget *target) {
    target->draw(shape);
}

//Update the button status
void Button::update(sf::Vector2f mousePosition, Player& player, int xSize) {
    //Idle
    buttonState = BTN_IDLE; //status IDLE: mouse isn't over the button

    //Hover
    if(shape.getGlobalBounds().contains(mousePosition)){
        buttonState = BTN_HOVER; //status HOVER: mouse is over the button

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            buttonState = BTN_PRESSED; //status PRESSED: the player has selected the plant on this button
        }
    }

    switch (buttonState) {
        case BTN_IDLE:
            shape.setSize(sf::Vector2f{static_cast<float>(xSize*BUTTON_SCALE),static_cast<float>(xSize*BUTTON_SCALE)});
            break;

        case BTN_HOVER:
            shape.setSize(sf::Vector2f{static_cast<float>(xSize*BUTTON_BIG_SCALE),static_cast<float>(xSize*BUTTON_BIG_SCALE)}); //when mouse over button became bigger
            break;

        case BTN_PRESSED:
            player.select(plantID); //selected plant change
            break;

        default:
            break;
    }
    shape.setTexture(&buttonImage); //the image is applied on the button
}



