//
// Created by david on 27/07/2022.
//

#include "Player.h"

void Player::increaseEnergy(){
    this->energy+=1;
};
void Player::select(int selected){
    this->selectedPlant=selected;
};