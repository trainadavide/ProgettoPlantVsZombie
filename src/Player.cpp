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
};