//
// Created by david on 26/07/2022.
//

#ifndef PLANTVSZOMBIE_PLANT_H
#define PLANTVSZOMBIE_PLANT_H


class Plant {

private:
    int hp;
    int cost;
    int x;
    int y;

    ~Plant();

public:
    void takeDamage(int damage);
};


#endif //PLANTVSZOMBIE_PLANT_H
