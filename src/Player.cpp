//
// Created by david on 27/07/2022.
//

#include "Player.h"

Player::Player(int energy, sf::Vector2<unsigned int> screenSize){
    this->energy = energy;

    this->initFont();

    //set assets for energy
    energyDisplay.setCharacterSize(screenSize.x*FONT_RESIZABLE);
    energyDisplay.setFillColor(sf::Color::Black);
    energyDisplay.setPosition(screenSize.x*FONT_POSITION_X,screenSize.y*FONT_POSITION_Y);
    energyDisplay.setFont(textFont);

    //set assets selection
    selectedDisplay.setCharacterSize(screenSize.x*FONT_RESIZABLE);
    selectedDisplay.setFillColor(sf::Color::Black);
    selectedDisplay.setPosition(screenSize.x*FONT_POSITION_X,screenSize.y*FONT_POSITION_Y_S);
    selectedDisplay.setFont(textFont);

    //set assets for infoBox
    playerInfo.setSize({static_cast<float>(screenSize.x*INFO_DIM_X),static_cast<float>(screenSize.y*INFO_DIM_Y)});
    playerInfo.setPosition(screenSize.x*INFO_POS_X,screenSize.y*INFO_POS_Y);
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
    //update energy to display
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
