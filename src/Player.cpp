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
    energyDisplay.setPosition(1010,12);
    energyDisplay.setFont(textFont);

    playerInfo.setSize({600,150});
    playerInfo.setPosition(1000,10);
    playerInfo.setFillColor(sf::Color::Cyan);
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

    char val[5];
    sprintf(val,"%d", this->energy);
    sf::String testo = "Energia: ";
    testo.insert(9,val);
    energyDisplay.setString(testo);

    target->draw(energyDisplay);
};

void Player::update(sf::RenderTarget* target){
    target->draw(this->playerInfo);

    char val[5];
    sprintf(val,"%d", this->energy);
    sf::String testo = "Energia: ";
    testo.insert(9,val);
    energyDisplay.setString(testo);

    target->draw(energyDisplay);
}