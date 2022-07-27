//
// Created by david on 26/07/2022.
//

#ifndef PLANTVSZOMBIE_PLANT_H
#define PLANTVSZOMBIE_PLANT_H


class Plant {

private:
    int x;
    int y;
    int hp;
    int cost;

protected:
    int getHp() const;
    void setHp(int hp);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    int getCost() const;
    void setCost(int cost);
    ~Plant();

public:
    void takeDamage(int damage);
};


#endif //PLANTVSZOMBIE_PLANT_H
