//
// Created by david on 27/07/2022.
//

#include "Player.h"

Player::Player(int energy){
    this->energy = energy;

    this->initFont();

    energyDisplay.setCharacterSize(80);
    energyDisplay.setFillColor(sf::Color::Black);
    energyDisplay.setPosition(1010,10);
    energyDisplay.setFont(textFont);

    selectedDisplay.setCharacterSize(80);
    selectedDisplay.setFillColor(sf::Color::Black);
    selectedDisplay.setPosition(1010,65);
    selectedDisplay.setFont(textFont);

    playerInfo.setSize({650,150});
    playerInfo.setPosition(1000,10);
    playerInfo.setFillColor(sf::Color(200,70,20));
}

void Player::initFont() {
    if(!textFont.loadFromFile("../font/balls-on-the-rampage/BallsoOnTheRampage.ttf")){
        printf("Font doesn't load");
    }
}

void Player::increaseEnergy(){
    this->energy+=1;
}
void Player::select(int selected){
    this->selectedPlant=selected;
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->playerInfo);

    target->draw(energyDisplay);

    target->draw(selectedDisplay);
}

void Player::update(){

    char val[5];
    sprintf(val,"%d", this->energy);
    sf::String testo = "Energy: ";
    testo.insert(8,val);
    energyDisplay.setString(testo);

    switch (this->selectedPlant) {
        case 0:
            testo = "Plant: sunflower";
            break;
        case 1:
            testo = "Plant: nut";
            break;
        case 2:
            testo = "Plant: shooter plant";
            break;
        case 3:
            testo = "Plant: ice plant";
            break;
        case 4:
            testo = "Plant: fire plant";
            break;
    }
    selectedDisplay.setString(testo);
}

int Player::getEnergy() const {
    return energy;
}

int Player::getSelectedPlant() const {
    return selectedPlant;
}

void Player::decreaseEnergy(int e) {
    this->energy-=e;
}
