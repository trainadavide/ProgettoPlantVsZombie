//
// Created by david on 27/07/2022.
//

#include "Player.h"
#include "Plants/Sunflower.h"
#include "Plants/Nut.h"
#include "Plants/GreenPlant.h"
#include "Plants/SnowPlant.h"
#include "Plants/FirePlant.h"
#define SUNFLOWER_COST 2
#define NUT_COST 2
#define GREEN_PLANT_COST 4
#define SNOW_PLANT_COST 7
#define FIRE_PLANT_COST 7

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
};
void Player::select(int selected){
    this->selectedPlant=selected;
}

void Player::place(Map m, int x, int y) {
    if(m.isEmpty(x,y)){
        Plant *p;
        switch (this->selectedPlant) {
            case 0:
                if(this->energy>=SUNFLOWER_COST){
                    p = new Sunflower(x,y);
                    m.setPlant(p,x,y);
                    this->energy-=SUNFLOWER_COST;
                    delete p;
                }
                break;
            case 1:
                if(this->energy>=NUT_COST) {
                    p = new Nut(x, y);
                    m.setPlant(p, x, y);
                    this->energy-=NUT_COST;
                    delete p;
                }
                break;
            case 2:
                if(this->energy>=GREEN_PLANT_COST) {
                    p = new GreenPlant(x, y);
                    m.setPlant(p, x, y);
                    this->energy-=GREEN_PLANT_COST;
                    delete p;
                }
                break;
            case 3:
                if(this->energy>=SNOW_PLANT_COST) {
                    p = new SnowPlant(x, y);
                    m.setPlant(p, x, y);
                    this->energy-=SNOW_PLANT_COST;
                    delete p;
                }
                break;
            case 4:
                if(this->energy>=FIRE_PLANT_COST) {
                    p = new FirePlant(x, y);
                    m.setPlant(p, x, y);
                    this->energy-=FIRE_PLANT_COST;
                    delete p;
                }
                break;
        }
    }
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->playerInfo);

    target->draw(energyDisplay);

    target->draw(selectedDisplay);
};

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