//
// Created by david on 14/09/2022.
//

#include "Button.h"
#define BUTTONSPOSY 10;

Button::Button(int position, sf::Texture &buttonImage) {

    this->plantID = position;
    this->buttonImage = buttonImage;
    this->buttonState=BTN_IDLE;

    this->x=180*position;
    this->y=BUTTONSPOSY;
    this->shape.setPosition(sf::Vector2f(this->x,this->y));

    this->shape.setSize(sf::Vector2f(150,150));
    this->shape.setTexture(&buttonImage);
}

Button::~Button() {

}

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

void Button::update(sf::Vector2f mousePosition, Player& player) {
    //Idle
    this->buttonState = BTN_IDLE;

    //Hover
    if(this->shape.getGlobalBounds().contains(mousePosition)){
        this->buttonState = BTN_HOVER;

        //Pressed
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState = BTN_PRESSED;
        }
    }

    switch (buttonState) {
        case BTN_IDLE:
            this->shape.setSize({150,150});
            break;

        case BTN_HOVER:
            this->shape.setSize({170,170});
            break;

        case BTN_PRESSED:
            player.select(plantID);
            break;

        default:
            break;
    }
    this->shape.setTexture(&buttonImage);
}

const bool Button::isPressed() const {
    if(this->buttonState == BTN_PRESSED)
        return true;
    return false;
}


