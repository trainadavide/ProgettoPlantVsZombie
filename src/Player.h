//
// Created by david on 27/07/2022.
//

#ifndef PLANTVSZOMBIE_PLAYER_H
#define PLANTVSZOMBIE_PLAYER_H



class Player {
private:
    int energy;
    int time;
    int selectedPlant;

public:
    void increaseEnergy();
    void select(int selected);
};


#endif //PLANTVSZOMBIE_PLAYER_H
