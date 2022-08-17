//
// Created by 0260863 on 26/07/2022.
//

#ifndef PROJECTPVSZ_ZOMBIE_H
#define PROJECTPVSZ_ZOMBIE_H


#include "../Plants/Plant.h"

class Zombie {
private:
    int hp;
    float x;
    int y;
    int strenght;
    bool iceStatus;
public:
    int getHp() const;
    void setHp(int hp);

    float getX()const;
    void setX(float x);

    int getY() const;
    void setY(int y);

    int getStrenght()const;
    void setStrenght(int damage);

    bool getStatus()const;
    void setStatus(bool status);

    ~Zombie();

    void attack(Plant p);
    void takeDamage(int damage);

};


#endif //PROJECTPVSZ_ZOMBIE_H
