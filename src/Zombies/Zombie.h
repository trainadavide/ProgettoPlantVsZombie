//
// Created by 0260863 on 26/07/2022.
//

#ifndef PROJECTPVSZ_ZOMBIE_H
#define PROJECTPVSZ_ZOMBIE_H


class Zombie {
private:
    int hp;
    float x;
    int y;
    int damage;
public:
    Zombie(int hp,float x,int y,int damage);
    ~Zombie();
    void attack(Plant);
    void takeDamage(int damage);
};


#endif //PROJECTPVSZ_ZOMBIE_H
